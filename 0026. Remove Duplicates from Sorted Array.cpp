// Task: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<iostream>
#include<vector>

int removeDuplicates(std::vector<int>& nums) {
	int count = 1;
	for (size_t i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[i - 1]) {
			nums[count] = nums[i];
			++count;
		}
	}
	return count;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 1, 2 };
	std::cout << removeDuplicates(vec1) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	std::cout << removeDuplicates(vec2) << "\n";

	return 0;
}
