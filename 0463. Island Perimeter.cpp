// Task : https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18 

#include <iostream>
#include <vector>

int islandPerimeter(std::vector<std::vector<int>> grid) {
	int P = 0;
	for (size_t i = 0; i < grid.size(); i++) {
		for (size_t j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				P += 4;
				if (i > 0 && grid[i - 1][j] == 1) {
					P -= 2;
				}
				if (j > 0 && grid[i][j - 1] == 1) {
					P -= 2;
				}
			}
		}
	}
	return P;
}

int main() {
	// Example 1:
	std::vector<std::vector<int>> vec1 = {
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0}
	};
	std::cout << islandPerimeter(vec1) << '\n';

	// Example 2:
	std::vector<std::vector<int>> vec2 = { { 1 } };
	std::cout << islandPerimeter(vec2) << '\n';

	// Example 3:
	std::vector<std::vector<int>> vec3 = { { 1, 0 } };
	std::cout << islandPerimeter(vec1) << '\n';

	return 0;
}
