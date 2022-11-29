#include<stdio.h>
#include<string.h>
#include "main.h"

void load_ecg_data(float input[1][1250][1]);
struct node lowpass_butter(struct node data,float para);
struct node bandpassfilter(struct node data,float signal_freq);
struct node ediff1d(struct node x);
struct node square(struct node x);
struct node findpeaks(struct node data,int spacing,int limit);
void detect_peaks();
void detect_qrs();
int *rrvt(float input[1][1250][1], float *result);