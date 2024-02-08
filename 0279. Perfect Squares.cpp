// Task: https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

#include<iostream>
#include<vector>

int numSquares(int n) {
	std::vector<int> vec(n + 1, 0);

	for (size_t i = 1; i <= n; i++) {
		int min = i, y = 1, sq = 1;
		while (sq <= i) {
			min = std::min(min, 1 + vec[i - sq]);
			++y;
			sq = y * y;
		}
		vec[i] = min;
	}
	return vec[n];
}

int main() {
	// Example 1:
	std::cout << numSquares(12) << "\n";
	
	// Example 2:
	std::cout << numSquares(13) << "\n";

	return 0;
}
