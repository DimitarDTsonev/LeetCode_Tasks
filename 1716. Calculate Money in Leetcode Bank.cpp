 // Task : https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

#include <iostream>

int totalMoney(int n) {
	int week = n / 7;
	int high = 28 + (7 * (week - 1));
	int total = (week * (28 + high)) / 2;

	for (int i = 0; i < n % 7; i++) {
		total += i + (week + 1);
	}
	return total;
}

int main() {
	// Example 1:
	std::cout << totalMoney(4) << '\n';

	// Example 2:
	std::cout << totalMoney(10) << '\n';

	// Example 3:
	std::cout << totalMoney(20) << '\n';

	return 0;
}
