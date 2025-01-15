#include "Tools.h"
#include <iostream>

int binaryGap(const int n) {
    int counter = sizeof(int) * -8;
    int counterMax = 0;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        int t = n >> i;
        counter++;
        if (t & 1) {
            std::cout << "I have met 1 bit on position " << i << std::endl;
            if (counter > counterMax) {
                counterMax = counter;
            }
            counter = 0;
        }
    }
    return counterMax;
}

int minBitFlips(int start, int goal) {
    int xorResult = start ^ goal;
    int count = 0;
    while (xorResult) {
        count++;
        xorResult &= (xorResult - 1);
    }
    return count;
}
