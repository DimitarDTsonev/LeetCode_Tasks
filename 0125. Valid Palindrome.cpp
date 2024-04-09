// Task : https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
	std::string s1;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
			s1.push_back(s[i]);
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s1.push_back(s[i] + 32);
		}
	}

	std::string s2(s1);
	std::reverse(s1.begin(), s1.end());

	return s1 == s2;
}

int main() {
	// Example 1:
	std::cout << isPalindrome("A man, a plan, a canal: Panama") << '\n';

	// Example 2:
	std::cout << isPalindrome("race a car") << '\n';

	// Example 3:
	std::cout << isPalindrome(" ") << '\n';

	return 0;
}
