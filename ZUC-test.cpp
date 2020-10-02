#include <iostream>
#include <vector>
#include <string>

#include "include/ZUC.h"

int main(int argc, char *argv[]) {
    unsigned char iv[16] = {0x84, 0x31, 0x9a, 0xa8, 0xde, 0x69, 0x15, 0xca, 0x1f, 0x6b, 0xda, 0x6b, 0xfb, 0xd8, 0xc7,
                            0x66};

    // initialize key (128 = 16 * 8)
    std::string key_string = "1234567890123456";
    if (key_string.size() != 16) {
        std::cout << "Bad key size:" << key_string.size() << std::endl;
        return -1;
    }
    // convert to C type
    u8 *key = (u8 *) key_string.c_str();

    // how many keys are generated
    int keyStreamSize = 16;

    // save keys to pKeyStream[]
    vector<uint32> pKeyStream(keyStreamSize);

    // initialize
    Initialization(key, iv);
    // generate
    GenerateKeyStream(pKeyStream, keyStreamSize);

    std::cout << "Generated key stream:" << std::endl << std::endl;

    // output as hexadecimal
    for (int i = 0; i < keyStreamSize; ++i) {
        std::cout << std::dec << i << "\t0x" << std::hex << pKeyStream[i] << std::endl;
    }
    std::cout << sizeof(double) << std::endl;
    return 0;
}
