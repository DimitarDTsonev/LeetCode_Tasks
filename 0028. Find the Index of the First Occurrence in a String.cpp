// Task: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include<iostream>
#include<string>

int strStr(std::string haystack, std::string needle) {
	for (size_t i = 0; i < haystack.length(); i++) {
		if (needle[0] == haystack[i]) {
			if (needle == haystack.substr(i, needle.size())) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	// Example 1:
	std::cout << strStr("sadbutsad", "sad") << "\n";

	// Example 2:
	std::cout << strStr("leetcode", "leeto") << "\n";

	return 0;
}
