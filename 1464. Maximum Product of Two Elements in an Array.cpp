// Task : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=problem-list-v2&envId=an1rjax7

#include <iostream>
#include <vector>
#include <algorithm>

int maxProduct(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return (nums[nums.size() - 2] - 1) * (nums[nums.size() - 1] - 1);
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 3, 4, 5, 2 };
    std::cout << maxProduct(vec1) << '\n';
    
    // Example 2:
    std::vector<int> vec2 = { 1, 5, 4, 5 };
    std::cout << maxProduct(vec2) << '\n';

    // Example 1:
    std::vector<int> vec3 = { 3, 7, };
    std::cout << maxProduct(vec3) << '\n';

    return 0;
}
