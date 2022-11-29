/**
  ******************************************************************************
  * @file    network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Oct  9 17:47:39 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_weights_array_u64[187] = {
  0x3f4925993e223800U, 0x3fa1610b3f72a50cU, 0x3f5cee5b3f4ff42aU, 0x3f51ace93f00c7bfU,
  0x3f01f9883ef3cdc6U, 0xbe566dd73dc38c44U, 0x3df40f28be1684f4U, 0x3f333d1f3eec1fd9U,
  0x3d0b6aef3f0fbad5U, 0xbebf3554bf2633d7U, 0xbebee1e7bf0385fcU, 0xbf1c3d50be1523deU,
  0x3e9b41983e9120abU, 0xbe2eefa23d6457cfU, 0x3eb085603c87fa92U, 0xbe679b2b3edef178U,
  0xbe9877bcbed79aceU, 0x3f514b9f3e407554U, 0xbe1d30273f0bfd91U, 0x3d704514bd8067faU,
  0x3e88127b3ec022fbU, 0xbea749e6bd86ecd0U, 0x3d974ebebed3627fU, 0xbe5d4434bf03d106U,
  0x4211146a4109d5e1U, 0xbf52e8c541af60ebU, 0xbdfaa98abd681087U, 0xbd358e2cbf107c8dU,
  0x3e8912d0bec9ccf1U, 0x3e4fe8403e3fd89bU, 0xbe6b30953f0864cbU, 0xbe7393e1bde0f994U,
  0x3e624bcebef6b64cU, 0xbf28f5b9bfa05610U, 0xbe8938593e9cbc7aU, 0x3cffb8debe905251U,
  0x3df5e31a3f089049U, 0x3ec403f33e0b65f6U, 0xbe4d9594bc0e87c0U, 0xbeb4ad64be4f4541U,
  0xbeacc2ff3ed01c15U, 0x3cc22fc73d51577bU, 0xbc7dd9acbe273013U, 0xbe9e975f3cdfcb3cU,
  0x3ec7aeb2bf0eeb59U, 0xbc8b51c7be95e285U, 0xbf55d4963e607179U, 0xbea52abbbedc4aeaU,
  0xbd490e343d102612U, 0x3e3f493abd7f24b2U, 0xbde11976bc1fbc54U, 0xbd39cf4d3db1afb0U,
  0xbd5e32e43d7ff0c9U, 0xbe978a0abc0b0b51U, 0xbdfe2cc83e3ccf0eU, 0x3dc05fd0bec08b89U,
  0xbe9ad2f83d1e1e95U, 0xbec649c63ddf5a24U, 0xbe670c00bdb2175dU, 0x3d98cdecbe98ff2aU,
  0x4027203140017399U, 0xbef4a1eb3fe6635dU, 0xbecf7236bea9686eU, 0xbd8e1fd0bdac4ffcU,
  0xbd48beb0bd6e35e2U, 0xbcee2335bd21230eU, 0xbbdcc5e6bc90faabU, 0x3c9186bb3bb89dd0U,
  0x3d28c33d3cf2dee7U, 0x3d7229683d504e9eU, 0x3da897733d8e38efU, 0x5586255477247486U,
  0x7626344235353546U, 0x2666424361434654U, 0x6667246866424428U, 0x4235452661235636U,
  0x8343624455465475U, 0x7553354355334365U, 0x3543345546413334U, 0x3355533335555313U,
  0x1155161234554336U, 0x5013343316544575U, 0x4343335753414223U, 0x4246334424425443U,
  0x3633242424253443U, 0x1515144355233432U, 0x5453224235544460U, 0x2125023134423315U,
  0x2435124314444534U, 0x7624374412515250U, 0x9ad99aaa9a89a846U, 0x9ad99bba89aeebb8U,
  0xb9aacbb99aa99cdbU, 0xa9a9a9888bc78b9dU, 0x988cba969ab9ba8bU, 0x9bbeaa98d99a7babU,
  0xcce8ba8b8c9c8cc8U, 0xaae89a9ab99aca88U, 0xbbd9b8bd8b8bda89U, 0xbaca8bc7eaaaaaabU,
  0xc9aaadd898aba9acU, 0xc989a88ecb9dc9b8U, 0xaa9acc99cdc8a9adU, 0x98abdb9d7b9b98c8U,
  0x7dab8a9acab9ac9cU, 0xa99ebbadb989cec8U, 0x9bcbabb989a9d9daU, 0xac9a7cbba8bdd7aaU,
  0xcab9bad8abdada97U, 0x687ba96b6559b97bU, 0x897998b7d589bcc5U, 0x6fc53a8bbb82ebb8U,
  0x5a9a8a5899abc569U, 0xa51ab7d6a39c9a96U, 0xaa477f94e5d78a97U, 0xb68ea88998665b5fU,
  0x587bf756cd93aa29U, 0x88879bc4d787979aU, 0x8b7769a9826b4bbbU, 0xd7e5849ab3486eaaU,
  0x75a965dc77aa6999U, 0x498b97956b8db86cU, 0xd2a68c48852aa95bU, 0xb576ca6ad7875be9U,
  0x9997686e6ca85a5aU, 0x77b991978da68e79U, 0x82caa8d53b59bac3U, 0xe7762c7bcb688699U,
  0xbb9a9aabb88b674dU, 0xbcaabbb7d9a9ba8aU, 0xbdbacaba9bcdabacU, 0xbbea9eaa9b9baaebU,
  0xbba9baba99a9bb9aU, 0x8acaec8b9ada8dabU, 0xaabbdaaabbbc7addU, 0x9bcadadbbdaddbdbU,
  0x9cdabb8accba9baaU, 0xadacbcbeac9dcaabU, 0xb9caccaddedda999U, 0xeabdbab9bcebaccaU,
  0xda99dc9dddbcccacU, 0xb9cbba9abeaaa9adU, 0xaecbccedbcbdacdcU, 0xbcbebeaadeabbcedU,
  0xf9eeadfdadccecfdU, 0xadfadbadfabbcbdcU, 0x9bc99bca9bbebcccU, 0x47589168c8baab8aU,
  0x4486533844657461U, 0x6643449563325946U, 0x2374667473263625U, 0x6772466482656358U,
  0x6353655314685350U, 0x6636357447757426U, 0x5454622573353724U, 0x5577645467343675U,
  0x5555751775351668U, 0x2624646623465753U, 0x6672453545556552U, 0x7463675624264346U,
  0x6281441347376267U, 0x7214367454535357U, 0x5546557166552685U, 0x4145323636436154U,
  0x3256753475365561U, 0x2755523628557384U, 0x9669a46773554676U, 0x590a6a6329a59465U,
  0x68447d1589686797U, 0x8767482c86731da5U, 0x382a7477798681a5U, 0x3b5965764947a559U,
  0x668696a4a2369474U, 0xa8455c38d4666197U, 0x3d4696497895531aU, 0x536bb19342888877U,
  0x544a899474637981U, 0x3785874963b0b58U, 0x48c5925bb396337aU, 0x9759a67761975258U,
  0x985869962a4c1a66U, 0xb69265d5842a5917U, 0x79b6499466676aa6U, 0x4c8597641ba7546cU,
  0x944466a7448b4887U, 0x4288724887a2U, 0xbac0f853bd00e683U,
};


ai_handle g_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

