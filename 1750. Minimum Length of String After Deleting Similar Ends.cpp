// Task: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

#include<iostream>
#include<string>

int minimumLength(std::string s) {
	int right = s.size() - 1;
	int left = 0;
	
	while (left < right && s[left] == s[right]) {
		char ch = s[left];

		while (left <= right && s[left] == ch) {
			++left;
		}
	
		while (right >= left && s[right] == ch) {
			--right;
		}
	}
	
	return right - left + 1;
}

int main() {
	// Example 1:
	std::cout << minimumLength("ca") << "\n";

	// Example 2:
	std::cout << minimumLength("cabaabac") << "\n";

	// Example 3:
	std::cout << minimumLength("aabccabba") << "\n";

	return 0;
}
