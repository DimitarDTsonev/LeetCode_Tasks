// Task : https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string kthDistinct(std::vector<std::string>& arr, int k) {
	std::unordered_map<std::string, unsigned> map;

	for (std::string& s : arr) {
		++map[s];
	}

	for (std::string& s : arr) {
		if (map[s] == 1) {
			--k;
			if (k == 0) {
				return s;
			}
		}
	}

	return "";
}

int main() {
	// Example 1: 
	std::vector<std::string> vec1 = { "d", "b", "c", "b", "c", "a" };
	std::cout << kthDistinct(vec1, 2) << '\n';

	// Example 2: 
	std::vector<std::string> vec2 = { "aaa", "aa", "a" };
	std::cout << kthDistinct(vec2, 1) << '\n';

	// Example 3: 
	std::vector<std::string> vec3 = { "a", "b", "a" };
	std::cout << kthDistinct(vec3, 3) << '\n';

	return 0;
}
