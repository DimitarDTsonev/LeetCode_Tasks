// Task: https://leetcode.com/problems/search-insert-position/ 

#include<iostream>
#include<vector>

int searchInsert(std::vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size();
	int mid = 0;

	if (target > nums[right- 1]) {
		return right;
	}

	while (left < right) {
		mid = left + (right - left) / 2;
		
		if (nums[mid] == target) {
			return mid;
		}

		if (target < nums[mid]) {
			right = mid - 1;
		}
		else if (target > nums[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return left;
}

int main() {
	// Example 1: 
	std::vector<int> vec1 = { 1, 3, 5, 6 };
	std::cout << searchInsert(vec1, 5) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 1, 3, 5, 6 };
	std::cout << searchInsert(vec2, 2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 1, 3, 5, 6 };
	std::cout << searchInsert(vec3, 7) << "\n";

	return 0;
}
