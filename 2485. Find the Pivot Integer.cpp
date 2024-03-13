// Task: https://leetcode.com/problems/find-the-pivot-integer/description/

#include<iostream>

int pivotInteger(int n) {
	int res;

	if (n == 1) {
		return 1;
	}

	res = n * (n + 1) / 2;

	if (ceil((double)sqrt(res)) == floor((double)sqrt(res))) {
		return sqrt(res);
	}
	else {
		return -1;
	}
}

int main() {
	// Example 1: 
	std::cout << pivotInteger(8) << "\n";

	// Example 2: 
	std::cout << pivotInteger(1) << "\n";

	// Example 3: 
	std::cout << pivotInteger(4) << "\n";

	// Example 4: 
	std::cout << pivotInteger(15) << "\n";

	return 0;
}
