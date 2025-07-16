// Task : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16

#include <iostream>
#include <vector>

int maximumLength(std::vector<int>& nums) {
    int evenCnt = 0;
    int oddCnt = 0;
    int altEven = 0;
    int altOdd = 0;

    for (int num : nums) {
        if (num % 2 == 0) {
            ++evenCnt;
            altEven = altOdd + 1;
        } else {
            ++oddCnt;
            altOdd = altEven + 1;
        }
    }

    return std::max( { evenCnt, oddCnt, altEven, altOdd } );
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::cout << maximumLength(vec1) << '\n';

    // Example 2:
    std::vector<int> vec2 = { 1, 2, 1, 1, 2, 1, 2 };
    std::cout << maximumLength(vec2) << '\n';

    // Example 3: 
    std::vector<int> vec3 = { 1, 3 };
    std::cout << maximumLength(vec3) << '\n';
    return 0;
}
