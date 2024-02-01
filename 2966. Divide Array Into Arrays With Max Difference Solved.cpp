// Task: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	std::vector<std::vector<int>> res;

	for (int i = 0; i < nums.size(); i += 3) {
		if (k + nums[i] < nums[i + 2]) {
			return {};
		}

		res.push_back({ nums[i], nums[i + 1], nums[i + 2] });
	}

	return res;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < 3; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 3, 4, 8, 7, 9, 3, 5, 1 };
	std::vector<std::vector<int>> matrix1 = divideArray(vec1, 2);
	printMatrix(matrix1);

	// Example 2:
	std::vector<int> vec2 = { 1, 3, 3, 2, 7, 3 };
	std::vector<std::vector<int>> matrix2 = divideArray(vec2, 3);
	printMatrix(matrix2);

	return 0;
}
