// Task : https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04

#include <iostream>
#include <string>
#include <unordered_map>

int longestPalindrome(std::string s) {
	std::unordered_map<char, int> map;
	unsigned counter = 0;
	bool check = false;

	for (char iter : s) {
		map[iter]++;
	}

	for (auto& iter : map) {
		if (iter.second / 2 > 0) {
			if (iter.second % 2 == 0) {
				counter += iter.second;
			}
			else {
				check = true;
				counter += iter.second - 1;
			}
		}

		if (iter.second == 1) {
			check = true;
		}
	}
	if (check) {
		counter++;
	}

	return counter;
}

int main() {
	// Example 1:
	std::cout << longestPalindrome("abccccdd") << '\n';

	// Example 2:
	std::cout << longestPalindrome("a") << '\n';

	return 0;
}
