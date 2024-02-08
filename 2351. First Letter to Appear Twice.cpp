// Task: https://leetcode.com/problems/first-letter-to-appear-twice/description/

#include<iostream>
#include<string>
#include<unordered_map>

char repeatedCharacter(std::string s) {
	std::unordered_map<char, int> seen;

	for (char ch : s) {
		if (seen.find(ch) != seen.end()) {
			return ch;
		}
		else {
			seen[ch] = 1;
		}
	}
	return '\0';
}

int main() {
	// Example 1:
	std::cout << repeatedCharacter("abccbaacz") << "\n";
	
	// Example 2:
	std::cout << repeatedCharacter("abcdd") << "\n";

	return 0;
}
