#include<stdio.h>
#include<string.h>
#include "main.h"
#include "app_x-cube-ai.h"
struct node                 
{
    float a[1450];
    int top;
};


int signal_frequency= 250 ;                
int filter_order= 1 ;                     
int upper_threshold = 100; 
int lower_threshold = 40;
int findpeaks_spacing= 30;
float findpeaks_limit= 0.0005;
float refractory_period =30;                
float qrs_peak_filtering_factor= 0.125 ;    

//---------------
struct node ecg_data_raw; 
struct node detected_peaks_indices; 
struct node detected_peaks_values;       
//---------------
float qrs_peak_value = 0.0;           
float noise_peak_value = 0.0;
float threshold_value = 0.0;              

struct node qrs_peaks_indices;                  
int find_value = 30;                        


void load_ecg_data(float input[1][1250][1]) 
{
    ecg_data_raw.top=0;
    for(int16_t i=0;i<1;i++)
    {
      for(int16_t j=0;j<1250;j++)
      {
        for(int16_t k=0;k<1;k++)
        {
          ecg_data_raw.a[ecg_data_raw.top] = input[i][j][k];
					ecg_data_raw.top++;
        }

      }
    }

}

void lowpass_butter(struct node *data,float para)   
{
    struct node ans;
    ans.top=data->top;
    float last_data;
    for(int i=0;i<data->top;i++)
    {
        data->a[i]=last_data*(1-para)+data->a[i]*para;
        last_data=data->a[i];
    }
}

void bandpassfilter(struct node *data,float signal_freq)
{
    float nyquist_freq = 0.5 * signal_freq;                                 

    lowpass_butter(data,15 / nyquist_freq);
}

void ediff1d(struct node *x)     
{
    for(int i=0;i<x->top-2;i++)
    {
        x->a[i]=x->a[i+1]-x->a[i];
    }
}

void square(struct node *x)    
{
    for(int i=0;i<x->top;i++)
        x->a[i]=x->a[i]*x->a[i];
}

void findpeaks(struct node *data, struct node *detected_peaks_indices, int spacing,int limit)
{
    int i;
    struct node x;
    x.top=data->top+2*spacing;
    for(i=0;i<spacing;i++)
        x.a[i]=data->a[0]-1e-6;
    for(i=x.top-spacing;i<x.top;i++)
        x.a[i]=data->a[data->top-1]-1e-6;
    for(i=0;i<data->top;i++)
        x.a[i+spacing]=data->a[i];
    int peak_candidata[1350];
    for(i=0;i<data->top;i++)
        peak_candidata[i]=1;
    int start1,start2,start3;
    for(i=0;i<spacing;i++)
    {
        start2=spacing-i-1;
        start3=spacing;
        start1=spacing+i+1;
        for(int j=0;j<data->top;j++)
            peak_candidata[j]=(peak_candidata[j]>0)&&((x.a[start3+j]>(x.a[start1+j]>x.a[start2+j]?x.a[start1+j]:x.a[start2+j])));
    }
    detected_peaks_indices->top=0;
    for(i=0;i<data->top;i++)
    {
        if(peak_candidata[i])
        {
            
            if(data->a[i]>0.0005)
            {
                detected_peaks_indices->a[detected_peaks_indices->top]=i;
                detected_peaks_indices->top++;
            }
        }
    }
}

void detect_peaks()
{
    bandpassfilter(&ecg_data_raw,signal_frequency);

    for(int i=0;i<4;i++)
      ecg_data_raw.a[i]=ecg_data_raw.a[4];

    ediff1d(&ecg_data_raw);
    square(&ecg_data_raw);
    findpeaks(&ecg_data_raw,&detected_peaks_indices,findpeaks_spacing,findpeaks_limit);

    detected_peaks_values.top=detected_peaks_indices.top;
    for(int i=0;i<detected_peaks_indices.top;i++)
        detected_peaks_values.a[i]=ecg_data_raw.a[(int)(detected_peaks_indices.a[i])];
}

void detect_qrs()
{
    int flag=1;
    float last_qrs_index;
		qrs_peaks_indices.top = 0;
    for(int i=0;i<detected_peaks_indices.top;i++)
    {
        float detected_peak_index,detected_peaks_value;
        detected_peak_index=detected_peaks_indices.a[i];
        detected_peaks_value=detected_peaks_values.a[i];
        if(flag)
        {
            last_qrs_index=0;
            flag=0;
        }
        else
        {
            last_qrs_index=qrs_peaks_indices.a[qrs_peaks_indices.top-1];
        }
        
        if(detected_peak_index-last_qrs_index > refractory_period || ! qrs_peaks_indices.top)
        {
            if(detected_peaks_value > threshold_value)
            {
                qrs_peaks_indices.a[qrs_peaks_indices.top]=detected_peak_index;
                qrs_peaks_indices.top++;

                qrs_peak_value=qrs_peak_filtering_factor*detected_peaks_value + (1-qrs_peak_filtering_factor)*qrs_peak_value;
            }
        }
    }
}


int *rrvt(float input[1][1250][1], float *result)
{
		float total_rr = 0;
		float heart_rate;
		load_ecg_data(input);
    detect_peaks();
    detect_qrs();
		float rr_intervals[qrs_peaks_indices.top-1];
		
		if(qrs_peaks_indices.top < 4)
			aiRun(input, result);
		else
		{
			for(uint16_t i = 0; i<(qrs_peaks_indices.top); i++)
			{	
				if(i == 0)
					continue;
				else
				{
					rr_intervals[i-1] = ((float)(qrs_peaks_indices.a[i] - qrs_peaks_indices.a[i-1])/(float)250);
				} 
			}
			
			if((sizeof(rr_intervals)/sizeof(rr_intervals[0])) < 3)
				aiRun(input, result);
			else
			{
				for(uint16_t j = 0; j < (sizeof(rr_intervals)/sizeof(rr_intervals[0])); j++)
				{
					total_rr += rr_intervals[j];
				}
				heart_rate = (float)60/((total_rr/(float)(sizeof(rr_intervals)/sizeof(rr_intervals[0]))));
				if(heart_rate > upper_threshold)
				{
					result[0] = 0.0;
					result[1] = 1.0;
				}
				else if(heart_rate < lower_threshold)
				{
					result[0] = 1.0;
					result[1] = 0.0;
				}
				else
					aiRun(input, result);
			}
		}
		
		return 0;
}