// Task: https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

std::string customSortString(std::string order, std::string s) {
    std::unordered_map<char, int> map;
    for (int i = 0; i < order.length(); ++i) {
        map[order[i]] = i;
    }

    std::sort(s.begin(), s.end(), [&](char a, char b) {
        if (map.find(a) != map.end() && map.find(b) != map.end()) {
            return map[a] < map[b];
        }
        else if (map.find(a) != map.end()) {
            return true;
        }
        else if (map.find(b) != map.end()) {
            return false;
        }
        return a < b;
        });

    return s;
}

int main() {
	// Example 1:
	std::cout << customSortString("cba", "abcd") << "\n";

	// Example 2:
	std::cout << customSortString("bcafg", "abcd") << "\n";

	// Example 3:
	std::cout << customSortString("exv", "xwvee") << "\n";

	return 0;
}
