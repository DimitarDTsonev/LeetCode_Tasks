// Task : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/?envType=problem-list-v2&envId=an1rjax7

#include <iostream>
#include <vector>
#include <algorithm>

int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int min = nums[0], count = 0;
    for (int it : nums) {
        if (it - min > k) {
            min = it;
            ++count;
        }
    }
    return 1 + count;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 3, 6, 1, 2, 5 };
    std::cout << partitionArray(vec1, 2) << '\n';

    // Example 2:
    std::vector<int> vec2 = { 1, 2, 3 };
    std::cout << partitionArray(vec2, 1) << '\n';

    // Example 3:
    std::vector<int> vec3 = { 2, 2, 4, 5 };
    std::cout << partitionArray(vec3, 0) << '\n';

    return 0;
}
