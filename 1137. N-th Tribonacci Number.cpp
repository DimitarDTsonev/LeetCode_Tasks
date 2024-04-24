// Task : https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

#include <iostream>
#include <vector>

int tribonacci(int n) {
	if (n == 0) {
		return 0;
	}

	std::vector<unsigned long long> memo(n + 1, 0);
	memo[1] = 1;
	memo[2] = 1;

	for (size_t i = 3; i < n + 1; i++) {
		memo[i] = memo[i - 3] + memo[i - 2] + memo[i - 1];
	}

	return memo[n];
}

int main() {
	// Example 1:
	std::cout << tribonacci(4) << '\n';

	// Example 2:
	std::cout << tribonacci(25) << '\n';

	// Example 3:
	std::cout << tribonacci(1) << '\n';

	return 0;
}
