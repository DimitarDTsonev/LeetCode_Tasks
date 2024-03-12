// Task: https://leetcode.com/problems/powx-n/description/

#include<iostrea>

double myPow(double x, int n) {
	double num = std::pow(x, n);
	return num;
}

int main() {
	// Example 1:
	std::cout << myPow(2.00000, 10) << "\n";

	// Example 2:
	std::cout << myPow(2.10000, 3) << "\n";
	
	// Example 3:
	std::cout << myPow(2.00000, -2) << "\n";

	return 0;
}
