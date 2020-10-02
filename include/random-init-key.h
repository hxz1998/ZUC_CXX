/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */

#ifndef ZUC_CXX_RANDOM_INIT_KEY_H
#define ZUC_CXX_RANDOM_INIT_KEY_H

#include <chrono>
#include <string>

using namespace std;

/**
 * 获取到一个 128 位的初始密钥
 * 暂时使用 纪元时间 的拼接来获取
 *  拼接方法：[5F769467]->[6794765F6794765F6794765F6794765F]
 * 这里需要进行修改！以确定初始密钥的安全性！
 *
 * @return 128 位的初始密钥
 */
unsigned char *get_init_key() {
    /**
     * 格式：time_t : __time64_t -> __int64 -> long long
     */
    time_t now = time(nullptr); // 获取纪元时
    time_t buf = now;                   // buf 用来位移操作，每 4 个周期重置一次
    unsigned char epoch = 4;
    // 初始密钥
    unsigned char *init_key = new unsigned char[16];
    // 窗口
    unsigned char window = 0xFF, window_size = 8;
    for (int i = 0; i < 16; ++i) {
        init_key[i] = buf & window;
        buf >>= window_size;
        if ((i + 1) % epoch == 0 && i != 0) buf = now;
    }
    return init_key;
}

#endif //ZUC_CXX_RANDOM_INIT_KEY_H
