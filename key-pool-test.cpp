/**
 * Created by Xiaozhong on 2020/10/1.
 * Copyright (c) 2020/10/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <string>

#include "include/key-pool.h"

using namespace std;

int main() {
    int key_size = 20;
    int pool_size = 64;
    vector<vector<uint32>> pool(pool_size);
    unsigned char *key = (unsigned char *) string("1234567890123456").c_str();
    for (int i = 0; i < pool_size; ++i) {
        vector<uint32> keys = generate(key, key_size);
        pool[i] = keys;
    }
    for (int i = 0; i < pool_size; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << hex << pool[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    cout << "generate " << dec << pool.size() << " groups keys" << endl;
    cout << "each group contains " << pool[0].size() << " keys";
    return 0;
}