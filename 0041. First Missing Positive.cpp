// Task: https://leetcode.com/problems/first-missing-positive/description/?envType=list&envId=ppvcj88v

#include<iostream>
#include<vector>

int firstMissingPossitive(std::vector<int>& nums) {
	int size = nums.size(), i = 0;

	while (i < size) {
		if (nums[i] == i + 1) {
			++i;
		}
		else  if (nums[i] >= 1 && nums[i] <= size) {
			if (nums[i] == nums[nums[i] - 1]) {
				++i;
			}
			else {
				std::swap(nums[i], nums[nums[i] - 1]);
			}
		}
		else {
			++i;
		}
	}

	for (size_t i = 0; i < size; i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}
	return size;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 0, };
	std::cout << firstMissingPossitive(vec1) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 3, 4, -1, 1 };
	std::cout << firstMissingPossitive(vec2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 7, 8, 9, 11, 12 };
	std::cout << firstMissingPossitive(vec3) << "\n";

	return 0;
}
