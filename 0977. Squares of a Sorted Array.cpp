// Task: https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
	int size = nums.size();
	int left = 0;
	int right = size - 1;

	std::vector<int> res(size);

	for (int i = size - 1; i >= 0; --i) {
		if (std::abs(nums[left]) > std::abs(nums[right])) {
			res[i] = nums[left] * nums[left];
			++left;
		}
		else {
			res[i] = nums[right] * nums[right];
			--right;
		}
	}

	return res;
}

void printVec(const std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { -4, -1, 0, 3, 10 };
	printVec(sortedSquares(vec1));

	// Example 2:
	std::vector<int> vec2 = { -7, -3, 2, 3, 11 };
	printVec(sortedSquares(vec2));

	return 0;
}
