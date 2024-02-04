// Task: https://leetcode.com/problems/minimum-moves-to-convert-string/

#include<iostream>
#include<string>

int minimumMoves(std::string s) {
	int i = 0;
	int size = s.size();
	unsigned counter = 0;

	while (i < size) {
		if (s[i] == 'O') {
			++i;
		}
		else {
			++counter;
			i += 3;
		}
	}
	return counter;
}

int main() {
	// Example 1:
	std::cout << minimumMoves("XXXXX") << std::endl;

	// Example 2:
	std::cout << minimumMoves("OOOX") << std::endl;     

	//Example 3:
	std::cout << minimumMoves("XOOO") << std::endl;

	// Example 4:
	std::cout << minimumMoves("XXOX") << std::endl;     

	return 0;
}
