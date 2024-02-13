// Task: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

#include<iostream>
#include<string>
#include<vector>

bool isPalindrome(std::string str) {
	int i = 0;
	while (i < str.length() / 2) {
		if (str[i] != str[str.length() - i - 1]) {
			return false;
		}		
		++i;
	}
	return true;
}

std::string firstPalindrome(std::vector<std::string>& words) {
	int i = 0;
	while (i < words.size()) {
		if (isPalindrome(words[i])) {
			return words[i];
		}
		++i;
	}
	return "";
}

int main() { 
	// Example 1:
	std::vector<std::string> vec1 = { "abc", "car", "ada", "racecar", "cool" };
	std::cout << firstPalindrome(vec1) << "\n";

	// Example 2:
	std::vector<std::string> vec2 = { "notapalindrome", "racecar" };
	std::cout << firstPalindrome(vec2) << "\n";

	// Example 3:
	std::vector<std::string> vec3 = { "def", "ghi" };
	std::cout << firstPalindrome(vec3) << "\n";
	
	return 0;
}
