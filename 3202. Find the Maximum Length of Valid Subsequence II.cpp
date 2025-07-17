// Task : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17

#include <iostream>
#include <vector>

int maximumLength(std::vector<int>& nums, int k) {
    std::vector<std::vector<int>> dp(k, std::vector<int>(k, 0));
    int res = 0;
    int currRem = 0;

    for (int num : nums) {
        currRem = num % k;

        for (int prevRem = 0; prevRem < k; ++prevRem) {
            dp[prevRem][currRem] = dp[currRem][prevRem] + 1;
            res = std::max(res, dp[prevRem][currRem]);
        }
    }

    return res;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
    std::cout << maximumLength(vec1, 2) << '\n';
    
    // Example 2:
    std::vector<int> vec2 = { 1, 4, 2, 3, 1, 4 };
    std::cout << maximumLength(vec2, 3) << '\n';
    
    return 0;
}
