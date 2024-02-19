// Task: https://leetcode.com/problems/power-of-two/description/

#include<iostream>

bool isPowerOfTwo(int n) {
	return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
	// Example 1:
	std::cout << isPowerOfTwo(1) << "\n";

	// Example 2:
	std::cout << isPowerOfTwo(16) << "\n";

	// Example 3:
	std::cout << isPowerOfTwo(3) << "\n";

	return 0;
}
