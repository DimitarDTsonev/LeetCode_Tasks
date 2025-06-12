// Task : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12

#include <iostream>
#include <vector>
#include <cmath>

 int maxAdjacentDistance(std::vector<int>& nums) {
    int max = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        max = std::max(max, std::abs(nums[i + 1] - nums[i]));
    }
    max = std::max(max, std::abs(nums[nums.size() - 1] - nums[0]));

    return max;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = {  1, 2, 4 };
    std::cout << maxAdjacentDistance(vec1) << '\n';

    // Example 2:
    std::vector<int> vec1 = {  -5, -10, -5 };
    std::cout << maxAdjacentDistance(vec1) << '\n';

    return 0;
}
