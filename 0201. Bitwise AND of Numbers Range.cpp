// Task: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

#include<iostream>

int rangeBitwiseAnd(int left, int right) {
	int i = 0;

	while (left != right) {
		left >>= 1;
		right >>= 1;
		++i;
	}

	return left << i;
}

int main() {
	// Example 1:
	std::cout << rangeBitwiseAnd(5, 7) << "\n";
	
	// Example 2:
	std::cout << rangeBitwiseAnd(0, 0) << "\n";

	// Example 3:
	std::cout << rangeBitwiseAnd(1, 2147483647) << "\n";

	// Example 4:
	std::cout << rangeBitwiseAnd(1, 2) << "\n";

	// Example 5:
	std::cout << rangeBitwiseAnd(2, 4) << "\n";
	
	// Example 6:
	std::cout << rangeBitwiseAnd(2147483647, 2147483647) << "\n";

	return 0;
}
