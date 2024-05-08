// Task : https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
	std::vector<int> vec = score;
	int size = vec.size();
	std::vector<std::string> ranks;
	std::map<int, int> mp;

	sort(vec.begin(), vec.end(), std::greater<int>());
	for (int i = 0; i < size; i++) {
		mp[vec[i]] = i + 1;
	}

	for (int i : score) {
		if (mp.find(i) != mp.end()) {
			if (mp[i] == 1) {
				ranks.push_back("Gold Medal");
			}
			else if (mp[i] == 2) {
				ranks.push_back("Silver Medal");
			}
			else if (mp[i] == 3) {
				ranks.push_back("Bronze Medal");
			}
			else {
				ranks.push_back(std::to_string(mp[i]));
			}
		}
	}
	return ranks;
}

void printVec(std::vector<std::string> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 5, 4, 3, 2, 1 };
	printVec(findRelativeRanks(vec1));

	// Example 2:
	std::vector<int> vec2 = { 10, 3, 8, 9, 4 };
	printVec(findRelativeRanks(vec2));

	return 0;
}
