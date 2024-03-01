// Task: https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

#include<iostream>
#include<string>

std::string maximumOddBinaryNumber(std::string& s) {
	// It is guaranteed that there is at least one '1' in the string
	int size = s.size(), ones = -1;  

	for (size_t i = 0; i < size; ++i) {
		if (s[i] == '1') {
			++ones;
		}
	}
	s[size - 1] = '1';

	for (size_t i = 0; i < ones; ++i) {
		s[i] = '1';
	}

	for (size_t i = ones; i < size - 1; ++i) {
		s[i] = '0';
	}

	return s;
}

int main(){
	// Example 1:
	std::string s1 = "010";
	std::cout << maximumOddBinaryNumber(s1) << "\n";

	// Example 2:
	std::string s2 = "0101";
	std::cout << maximumOddBinaryNumber(s2) << "\n";

	return 0;
}
