// Task: https://leetcode.com/problems/longest-increasing-subsequence/

#include<iostream>
#include<vector>

int lengthOfLIS(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int n = nums.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    // Example 1:
	std::vector<int> vec1 = { 10, 9, 2, 5, 3, 7, 101, 18 };
    std::cout << lengthOfLIS(vec1) << std::endl;

    // Example 2:
    std::vector<int> vec2 = { 0, 1, 0, 3, 2, 3 };
    std::cout << lengthOfLIS(vec2) << std::endl;

    // Example 3:
    std::vector<int> vec3 = { 7, 7, 7, 7, 7, 7, 7 };
    std::cout << lengthOfLIS(vec3) << std::endl;

	return 0;
}
