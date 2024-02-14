// Task: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<string>
#include<numeric>

std::string gcdOfStrings(std::string str1, std::string str2) {
	return (str1 + str2 == str2 + str1) ? str1.substr(0, std::gcd(std::size(str1), std::size(str2))) : "";
}

int main() {
	// Example 1:
	std::cout << gcdOfStrings("ABCABC", "ABC") << "\n";

	// Example 2:
	std::cout << gcdOfStrings("ABABAB", "ABAB") << "\n";
	
	// Example 3:
	std::cout << gcdOfStrings("Leet", "Code") << "\n";

	return 0;
}
