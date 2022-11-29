/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Oct  9 17:47:39 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "b6cce9768e194d3b8d41b12e6f4bae3d"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Oct  9 17:47:39 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1250, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  node_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1854, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  node_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1854, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  node_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 918, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  node_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 918, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  node_23_to_chlast_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 918, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  node_24_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  node_17_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 45, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  node_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  node_19_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  node_19_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  node_20_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 63, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  node_20_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  node_22_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  node_22_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  node_24_weights_array, AI_ARRAY_FORMAT_LUT4_FLOAT,
  NULL, NULL, 1836, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  node_24_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1250), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &input_1_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  node_17_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 618), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_17_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  node_19_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 618), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_19_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  node_20_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 306), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_20_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  node_22_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 306), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_22_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  node_23_to_chlast_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 306, 3), AI_STRIDE_INIT(4, 4, 4, 4, 1224),
  1, &node_23_to_chlast_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  node_23_to_chlast_output0, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 918, 1, 1), AI_STRIDE_INIT(4, 4, 4, 3672, 3672),
  1, &node_23_to_chlast_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  node_24_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &node_24_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  node_17_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 15, 3), AI_STRIDE_INIT(4, 4, 4, 4, 60),
  1, &node_17_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  node_17_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_17_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  node_19_scale, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_19_scale_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  node_19_bias, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_19_bias_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  node_20_weights, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 3, 1, 7, 3), AI_STRIDE_INIT(4, 4, 12, 12, 84),
  1, &node_20_weights_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  node_20_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_20_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  node_22_scale, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_22_scale_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  node_22_bias, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &node_22_bias_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  node_24_weights, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 918, 2, 1, 1), AI_STRIDE_INIT(4, 1, 459, 918, 918),
  1, &node_24_weights_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  node_24_bias, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &node_24_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_23_to_chlast_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_24_weights, &node_24_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_24_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &node_24_chain,
  NULL, &node_24_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_23_to_chlast_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_23_to_chlast_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_23_to_chlast_layer, 7,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &node_23_to_chlast_chain,
  NULL, &node_24_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_WIDTH, AI_SHAPE_HEIGHT, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_22_scale, &node_22_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_22_layer, 6,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_22_chain,
  NULL, &node_23_to_chlast_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_20_weights, &node_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_20_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_20_chain,
  NULL, &node_22_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &node_19_scale, &node_19_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_19_layer, 3,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &node_19_chain,
  NULL, &node_20_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  node_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &node_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &node_17_weights, &node_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  node_17_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &node_17_chain,
  NULL, &node_19_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1496, 1, 1),
    1496, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 7504, 1, 1),
    7504, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &node_24_output),
  &node_17_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1496, 1, 1),
      1496, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 7504, 1, 1),
      7504, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &node_24_output),
  &node_17_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_1_output_array.data = AI_PTR(g_network_activations_map[0] + 2504);
    input_1_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2504);
    
    node_17_output_array.data = AI_PTR(g_network_activations_map[0] + 12);
    node_17_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12);
    
    node_19_output_array.data = AI_PTR(g_network_activations_map[0] + 12);
    node_19_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12);
    
    node_20_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    node_20_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    node_22_output_array.data = AI_PTR(g_network_activations_map[0] + 3672);
    node_22_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3672);
    
    node_23_to_chlast_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    node_23_to_chlast_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    node_24_output_array.data = AI_PTR(g_network_activations_map[0] + 3672);
    node_24_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3672);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    node_17_weights_array.format |= AI_FMT_FLAG_CONST;
    node_17_weights_array.data = AI_PTR(g_network_weights_map[0] + 0);
    node_17_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    
    node_17_bias_array.format |= AI_FMT_FLAG_CONST;
    node_17_bias_array.data = AI_PTR(g_network_weights_map[0] + 180);
    node_17_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 180);
    
    node_19_scale_array.format |= AI_FMT_FLAG_CONST;
    node_19_scale_array.data = AI_PTR(g_network_weights_map[0] + 192);
    node_19_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 192);
    
    node_19_bias_array.format |= AI_FMT_FLAG_CONST;
    node_19_bias_array.data = AI_PTR(g_network_weights_map[0] + 204);
    node_19_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 204);
    
    node_20_weights_array.format |= AI_FMT_FLAG_CONST;
    node_20_weights_array.data = AI_PTR(g_network_weights_map[0] + 216);
    node_20_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 216);
    
    node_20_bias_array.format |= AI_FMT_FLAG_CONST;
    node_20_bias_array.data = AI_PTR(g_network_weights_map[0] + 468);
    node_20_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 468);
    
    node_22_scale_array.format |= AI_FMT_FLAG_CONST;
    node_22_scale_array.data = AI_PTR(g_network_weights_map[0] + 480);
    node_22_scale_array.data_start = AI_PTR(g_network_weights_map[0] + 480);
    
    node_22_bias_array.format |= AI_FMT_FLAG_CONST;
    node_22_bias_array.data = AI_PTR(g_network_weights_map[0] + 492);
    node_22_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 492);
    
    node_24_weights_array.format |= AI_FMT_FLAG_CONST;
    node_24_weights_array.data = AI_PTR(g_network_weights_map[0] + 568);
    node_24_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 504);
    
    node_24_bias_array.format |= AI_FMT_FLAG_CONST;
    node_24_bias_array.data = AI_PTR(g_network_weights_map[0] + 1488);
    node_24_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1488);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 57248,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 57248,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_data_params_get(&params) != true) {
        err = ai_network_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_init(*network, &params) != true) {
        err = ai_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

