// Task: https://leetcode.com/problems/longest-palindromic-substring/description/

#include<iostream>
#include<string>

std::string longestPalindrome(std::string s) {
	std::string answer = s.substr(0, 1);
	int left, right;
	int n = s.size();

	for (int i = 0; i < n; ++i) {

		left = i - 1;
		right = i + 1;
		bool flag = false;

		while ((left >= 0 && right < n) && s[left] == s[right]) {
			left--;
			right++;
			flag = true;
		}

		if (flag && (right - left - 1) > answer.size()) {
			answer = s.substr(left + 1, right - left - 1);
		}

		left = i;
		right = i + 1;
		flag = false;

		while ((left >= 0 && right < n) && s[left] == s[right]) {
			left--;
			right++;
			flag = true;
		}

		if (flag && (right - left - 1) > answer.size()) {
			answer = s.substr(left + 1, right - left - 1);
		}
	}

	return answer;
}

int main() {
	// Example 1:
	std::string s1 = "babad";
	std::cout << longestPalindrome(s1) << std::endl;

	// Example 2:
	std::string s2 = "cbbd";
	std::cout << longestPalindrome(s2) << std::endl;

	return 0;
}
