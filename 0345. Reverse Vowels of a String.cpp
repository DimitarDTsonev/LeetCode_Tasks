// Task: https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include<iostream>
#include<string>

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'u' || ch == 'i' || ch == 'o' ||
		ch == 'A' || ch == 'E' || ch == 'U' || ch == 'I' || ch == 'O';
}

std::string reverseVowels(std::string s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (!isVowel(s[i]) && !isVowel(s[j])) {
			++i;
			--j;
		}
		if (!isVowel(s[i]) && isVowel(s[j])) {
			++i;
		}
		if (isVowel(s[i]) && !isVowel(s[j])) {
			--j;
		}
		if (isVowel(s[i]) && isVowel(s[j])) {
			std::swap(s[i], s[j]);
			++i;
			--j;
		}
	}
	return s;
}

int main() {
	// Example 1:
	std::cout << reverseVowels("hello") << "\n";

	// Example 2:
	std::cout << reverseVowels("leetcode") << "\n";

	return 0;
}
