/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */

#ifndef ZUC_CXX_KEY_POOL_H
#define ZUC_CXX_KEY_POOL_H

#include <string>
#include <vector>
#include "ZUC.h"

typedef unsigned int uint32;
typedef unsigned char u8;
using namespace std;

/**
 * 接收 8 * 16 (128)位的初始密钥，生成 keyStreamSize 个密钥流
 * @param key_string 初始密钥，长度必须是 128 位
 * @param keyStreamSize 生成多少个密钥，注意：每一个密钥只有 32 位
 * @return 密钥串
 */
vector<uint32> generate(unsigned char *key, int keyStreamSize) {
    vector<vector<uint32>> pool;
    unsigned char iv[16] = {0x84, 0x31, 0x9a, 0xa8, 0xde, 0x69, 0x15, 0xca, 0x1f, 0x6b, 0xda, 0x6b, 0xfb, 0xd8, 0xc7,
                            0x66};
    // save keys to pKeyStream[]
    vector<uint32> pKeyStream(keyStreamSize);
    // initialize
    Initialization(key, iv);
    // generate
    GenerateKeyStream(pKeyStream, keyStreamSize);
    return pKeyStream;
}

#endif //ZUC_CXX_KEY_POOL_H
