// Task : https://leetcode.com/problems/largest-local-values-in-a-matrix/description/?envType=daily-question&envId=2024-05-12

#include <iostream>
#include <vector>

std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
	unsigned size = grid.size();
	std::vector<std::vector<int>> res(size - 2, std::vector<int>(size - 2));

	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			int currMax = 0;

			for (int k = i - 1; k <= i + 1; k++) {
				for (int p = j - 1; p <= j + 1; p++) {
					currMax = std::max(currMax, grid[k][p]);
				}
			}
			res[i - 1][j - 1] = currMax;
		}
	}
	return res;
}

void printVec(std::vector<std::vector<int>> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec.size(); j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	// Example 1:
	std::vector<std::vector<int>> vec1 = { {9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2} };
	printVec(largestLocal(vec1));

	// Example 2:
	std::vector<std::vector<int>> vec2 = { { 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 2, 1, 1},
		{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1} };
	printVec(largestLocal(vec2));

	return 0;
}
