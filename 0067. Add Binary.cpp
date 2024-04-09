// Task: https://leetcode.com/problems/add-binary/description/

#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
	std::string res;
	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	int sum = 0;

	while (i >= 0|| j >= 0 || carry) {
		sum = carry;
		if (i >= 0) {
			sum += a[i--] - '0';
		}
		if (j >= 0) {
			sum += b[j--] - '0';
		}
		res.push_back(sum % 2 + '0');
		carry = sum / 2;
	}
	std::reverse(res.begin(), res.end());
	return res;
}

int main() {
	// Example 1:
	std::cout << addBinary("11", "1") << '\n';

	// Example 2:
	std::cout << addBinary("1010", "1011") << '\n';

	return 0;
}
