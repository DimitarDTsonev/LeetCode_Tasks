// Task: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

#include<iostream>
#include<vector>

std::vector<int> rearrangeArray(std::vector<int>& nums) {
	std::vector<int> toReturn(nums.size(), 0);
	int pos = 0, neg = 1;

	for (size_t i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			toReturn[pos] = nums[i];
			pos += 2;
		}
		else {
			toReturn[neg] = nums[i];
			neg += 2;
		}
	}

	return toReturn;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 3, 1, -2, -5, 2, -4 };
	printVec(rearrangeArray(vec1));

	// Example 2:
	std::vector<int> vec2 = { 1, -1 };
	printVec(rearrangeArray(vec2));

	return 0;
}
