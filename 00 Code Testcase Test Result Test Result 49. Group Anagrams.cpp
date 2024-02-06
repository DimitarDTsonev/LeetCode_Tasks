// Task: https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	std::vector<std::vector<std::string>> toReturn;
	std::unordered_map<std::string, std::vector<std::string>> map;

	for (const auto& str : strs) {
		std::string sortedStr = str;
		std::sort(sortedStr.begin(), sortedStr.end());
		map[sortedStr].push_back(str);
	}

	for (const auto& pair : map) {
		toReturn.push_back(pair.second);
	}

	return toReturn;
}

void printMat(const std::vector<std::vector<std::string>>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	// Example 1:
	std::vector<std::string> vec1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
	printMat(groupAnagrams(vec1));

	// Example 2:
	std::vector<std::string> vec2 = { "" };
	printMat(groupAnagrams(vec2));

	// Example 3:
	std::vector<std::string> vec3 = { "a" };
	printMat(groupAnagrams(vec3));

	return 0;
}
