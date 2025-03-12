// Task : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

#include <iostream>
#include <vector>

 int maximumCount(vector<int>& nums) {
    int negativeCount = 0;
    int size = nums.size();
    int iter = 0;
        
    for (; iter < size; iter++) {
        if (nums[iter] > 0) {
            return (size - iter) > negativeCount ? size - iter : negativeCount;
        } else if (nums[iter] == 0) {
            continue;
        }
        ++negativeCount;
    }

    return (size - iter) > negativeCount ? size - iter : negativeCount;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { -2, -1, -1, 1, 2, 3 };
    std::cout << maximumCount(vec1) << std::endl;

     // Example 2:
    std::vector<int> vec2 = { -3, -2, -1, 0, 0, 1, 2 };
    std::cout << maximumCount(vec2) << std::endl;

     // Example 3:
    std::vector<int> vec3 = { 5, 20, 66, 1314 };
    std::cout << maximumCount(vec3) << std::endl;

    return 0;
}
