// Task: https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>

bool increasingTriplet(std::vector<int>& nums) {
	int first = INT_MAX, second = INT_MAX;

	for (size_t i = 0; i < nums.size(); i++) {
		if (nums[i] <= first) {
			first = nums[i];
		}
		else if(nums[i] <= second) {
			second = nums[i];
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
	std::cout << increasingTriplet(vec1) << "\n";
	
	// Example 2:
	std::vector<int> vec2 = { 5, 4, 3, 2, 1 };
	std::cout << increasingTriplet(vec2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 2, 1, 5, 0, 4, 6 };
	std::cout << increasingTriplet(vec3) << "\n";

	return 0;
}
