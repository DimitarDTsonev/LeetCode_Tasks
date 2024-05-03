// Task : https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2024-05-03

#include <iostream>
#include <string>

int compareVersion(std::string version1, std::string version2) {
	const int size1 = version1.size();
	const int size2 = version2.size();
	int x1 = 0;
	int x2 = 0;

	for (int i = 0, j = 0; i < size1 || j < size2; i++, j++) {
		while (i < size1 && version1[i] != '.') {
			x1 = 10 * x1 + (version1[i++] - '0');
		}
		while (j < size2 && version2[j] != '.') {
			x2 = 10 * x2 + (version2[j++] - '0');
		}
		if (x1 < x2) {
			return -1;
		}
		else if (x1 > x2) {
			return 1;
		}
		x1 = 0;
		x2 = 0;
	}
	return 0;
}

int main() {
	// Example 1:
	std::cout << compareVersion("1.01", "1.001") << '\n';

	// Example 2:
	std::cout << compareVersion("1.01", "1.0.0") << '\n';

	// Example 3:
	std::cout << compareVersion("0.1", "1.1") << '\n';

	return 0;
}
