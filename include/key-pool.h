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
using namespace std;

vector<uint32> generate(const string &key_string, int keyStreamSize) {
    unsigned char iv[16] = {0x84, 0x31, 0x9a, 0xa8, 0xde, 0x69, 0x15, 0xca, 0x1f, 0x6b, 0xda, 0x6b, 0xfb, 0xd8, 0xc7,
                            0x66};

    // convert to C type
    unsigned char *key = (unsigned char *) key_string.c_str();

    // save keys to pKeyStream[]
    vector<uint32> pKeyStream(keyStreamSize);
    // initialize
    Initialization(key, iv);
    // generate
    GenerateKeyStream(pKeyStream, keyStreamSize);

    return pKeyStream;
}

#endif //ZUC_CXX_KEY_POOL_H
