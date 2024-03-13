// Task: https://leetcode.com/problems/longest-common-prefix/description/

#include<iostream>
#include<string>
#include<vector>

std::string longestCommonPrefix(std::vector<std::string> strs) {
	if (strs.size() == 0) {
		return "";
	}
	std::string prefix = strs[0];
	
	for (int i = 1; i < strs.size(); i++) {
		while (strs[i].find(prefix) != 0) {
			prefix = prefix.substr(0, prefix.length() - 1);
			
			if (prefix == "") {
				return "";
			}
		}
	}

	return prefix;
}

int main() {
	// Example 1: 
	std::vector<std::string> vec1 = { "flower", "flow", "flight" };
	std::cout << longestCommonPrefix(vec1) << "\n";

	// Example 2: 
	std::vector<std::string> vec2 = { "dog", "racecar", "car" };
	std::cout << longestCommonPrefix(vec2) << "\n";

	// Example 3: 
	std::vector<std::string> vec3 = { "" };
	std::cout << longestCommonPrefix(vec3) << "\n";

	return 0;
}
