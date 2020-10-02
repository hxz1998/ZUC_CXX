/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include "include/random-init-key.h"
#include "include/key-pool.h"

using namespace std;

int main() {
    unsigned char *key = get_init_key();
    vector<uint32> keys = generate(key, 20);
    for (int i = 0; i < 20; ++i) {
        cout << dec << i << " : " << hex << keys[i] << endl;
    }
    return 0;
}