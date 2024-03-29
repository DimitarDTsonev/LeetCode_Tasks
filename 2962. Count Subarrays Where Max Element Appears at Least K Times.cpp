// Task: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

#include <iostream>
#include <vector>

long long countSubarrays(std::vector<int>& nums, int k) {
	long long res = 0;
	int lft = 0;
	int rgh = 0;
	long long size = nums.size();
	long long max = *std::max_element(nums.begin(), nums.end());

	while (rgh < size) {
		k -= (nums[rgh++] == max);

		while (k == 0) {
			k += (nums[lft++] == max);
		}
		res += lft;
	}

	return res;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 3, 2, 3, 3 };
	std::cout << countSubarrays(vec1, 2) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 1, 4, 2, 1 };
	std::cout << countSubarrays(vec2, 3) << "\n";

	return 0;
}
