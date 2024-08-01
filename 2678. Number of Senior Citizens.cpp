// Task : https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01

#include <iostream>
#include <string>
#include <vector>

int countSeniors(std::vector<std::string>& details) {
	unsigned counter = 0;

	for (size_t i = 0; i < details.size(); i++) {
		if (details[i][11] > '6') {
			++counter;
		}
		else if (details[i][11] == '6' && details[i][12] > '0') {
			++counter;
		}
	}

	return counter;
}

int main() {
	// Example 1:
	std::vector<std::string> details1 = { "7868190130M7522", "5303914400F9211", "9273338290F4010" };
	std::cout << countSeniors(details1) << '\n';

	// Example 2:
	std::vector<std::string> details2 = { "1313579440F2036", "2921522980M5644" };
	std::cout << countSeniors(details2) << '\n';

	return 0;
}
