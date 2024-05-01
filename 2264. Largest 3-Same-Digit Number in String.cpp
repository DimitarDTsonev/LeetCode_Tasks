// Task : https://leetcode.com/problems/largest-3-same-digit-number-in-string/?envType=daily-question&envId=2024-05-01

#include <iostream>
#include <string>

std::string largestGoodInteger(std::string num) {
	char c = 0;
	unsigned l = 0;
	unsigned r = 0;

	for (unsigned i = 0; i < num.length() - 2; i++) {
		if ((num[i] == num[i + 1]) && (num[i + 1] == num[i + 2])) {
			if (c <= num[i]) {
				l = i;
				r = i + 2;
				c = num[i];
			}
		}
	}

	if (c) {
		return num.substr(l, 3);
	}
	return "";
}

int main() {
	// Example 1:
	std::cout << largestGoodInteger("6777133339") << '\n';
	
	// Example 2:
	std::cout << largestGoodInteger("2300019") << '\n';

	// Example 3:
	std::cout << largestGoodInteger("42352338") << '\n';

	return 0;
}
