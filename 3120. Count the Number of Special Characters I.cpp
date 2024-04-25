// Task : https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

#include <iostream>
#include <string>

int numberOfSpecialChars(std::string word) {
	bool lower[26] = { false };
	bool upper[26] = { false };
	int size = word.size();

	for (size_t i = 0; i < size; i++) {
		if (word[i] > 96) {
			lower[word[i] - 97] = true;
		}
		else {
			upper[word[i] - 65] = true;
		}
	}

	int res = 0;
	for (size_t i = 0; i < 26; i++) {
		if (lower[i] && upper[i]) {
			res++;
		}
	}

	return res;
}

int main() {
	// Example 1:
	std::cout << numberOfSpecialChars("aaAbcBC") << '\n';

	// Example 2:
	std::cout << numberOfSpecialChars("abc") << '\n';

	// Example 3:
	std::cout << numberOfSpecialChars("abBCab") << '\n';

	return 0;
}
