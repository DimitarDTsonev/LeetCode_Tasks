// Task : https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>

std::vector <std::vector<int >> subsets(std::vector<int>& nums) {
	int size = nums.size();
	int totalSize = pow(2, size);
	std::vector<std::vector<int>> res;
	
	for (int i = 0; i < totalSize; i++) {
		std::vector<int> toAdd;

		for (int j = 0; j < size; j++) {
			if (i & (1 << j)) {
				toAdd.push_back(nums[j]);
			}
		}
		res.push_back(toAdd);
	}
	return res;
}

void printMatrix(std::vector<std::vector<int>> mat) {
	for (size_t i = 0; i < mat.size(); i++) {
		std::cout << "{ ";
		for (size_t j = 0; j < mat[i].size(); j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << "} \n";
	}
	std::cout << '\n';
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3 };
	printMatrix(subsets(vec1));

	// Example 2:
	std::vector<int> vec2 = { 0 };
	printMatrix(subsets(vec2));

	return 0;
}
