// Task : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

#include <iostream>
#include <string>

int minimumRecolors(std::string blocks, int k) {
    int operations = INT_MAX;
    int bCount = 0;
        
    for (int i = 0; i < blocks.size(); ++i) {
        if (i - k >= 0 && blocks[i - k] == 'B') {
            --bCount;
        }
        if (blocks[i] == 'B') {
            bCount++;
        }
        operations = std::min(operations, k - bCount);
    }

    return operations;
}

int main() {
    // Example 1:
    std::cout << minimumRecolors("WBBWWBBWBW", 7);

    // Example 2:
    std::cout << minimumRecolors("WBWBBBW", 2);
    
    return 0;
}
