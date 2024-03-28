// Task: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

#include <iostream>
#include <vector>
#include <unordered_map>

int maxSubarrayLength(std::vector<int>& nums, int k) {
    int res = 0;
    std::unordered_map<int, int> map;
    int size = nums.size();

    for (int i = 0, j = 0; j < size; j++) {
        map[nums[j]]++; 
        
        if (map[nums[j]] > k) {
            while (nums[i] != nums[j]) {
                map[nums[i]]--;
                i++;
            }
            map[nums[i]]--;
            i++;
        }
        res = std::max(res, j - i + 1);
    }

    return res;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3, 1, 2, 3, 1, 2 };
	std::cout << maxSubarrayLength(vec1, 2) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 1, 2, 1, 2, 1, 2, 1, 2 };
	std::cout << maxSubarrayLength(vec2, 1) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 5, 5, 5, 5, 5, 5, 5 };
	std::cout << maxSubarrayLength(vec3, 1) << "\n";

	return 0;
}
