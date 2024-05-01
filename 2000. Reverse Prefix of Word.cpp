// Task : https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01

#include <iostream>
#include <string>

std::string reversePrefix(std::string word, char ch) {
	size_t iter = word.find(ch);
	
	if (iter != word.size()) {
		std::reverse(word.begin(), word.begin() + iter + 1);
	}

	return word;
}

int main() {
	// Example 1:
	std::cout << reversePrefix("abcdefd", 'd') << '\n';
	
	// Example 2:
	std::cout << reversePrefix("xyxzxe", 'z') << '\n';
	
	// Example 3:
	std::cout << reversePrefix("abcd", 'z') << '\n';

	return 0;
}
