// Task : https://leetcode.com/problems/reverse-bits/description/

#include <iostream>

uint32_t reverseBits(uint32_t n) {
    uint32_t num = 0;

    for (int i = 0; i < 32; i++) {
        num <<= 1;
        num |= (n & 1);
        n >>= 1;
    }

    return num;
}

int main() {
    // Example 1:
    std::cout << reverseBits(43261596) << '\n';

    // Example 2:
    std::cout << reverseBits(4294967293) << '\n';

    return 0;
}
