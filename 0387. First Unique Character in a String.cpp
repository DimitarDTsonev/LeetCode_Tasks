// Task: 

#include<iostream>
#include<string>
#include<unordered_map>

int firstUniqChar(std::string s) {
	if (s.empty()) {
		return -1;
	}
	std::unordered_map<char, std::pair<int, int>> map;

	for (int i = 0; i < s.size(); i++) {
		// or just use auto:
		const std::unordered_map<char, std::pair<int, int>>::iterator it = map.find(s[i]);

		if (it == map.end()) {
			map.insert({ s[i], {i, 1} });
		}
		else {
			++it->second.second;
		}
	}

	int min = INT_MAX;

	for (const auto& i : map) {
		if (i.second.second == 1 && i.second.first < min) {
			min = i.second.first;
		}
	}

	return (min != INT_MAX) ? min : -1;
}


/*
// Cool and faster solution than mine:

int firstUniqChar(std::string s) {
	int n = s.size();
	std::vector<int> arr(26, 0);

	for (char a : s) {
		arr[a - 'a']++;
	}

	int ans = -1;

	for (int i = 0; i < n; i++) {
		if (arr[s[i] - 'a'] == 1) {
			ans = i;
			break;
		}
	}

	return ans;
}
*/


int main() {
	// Example 1:
	std::string s1 = "leetcode";
	std::cout << firstUniqChar(s1) << std::endl;

	// Example 2:
	std::string s2 = "loveleetcode";
	std::cout << firstUniqChar(s2) << std::endl;

	// Example 3:
	std::string s3 = "aabb";
	std::cout << firstUniqChar(s3) << std::endl;

	std::string s4 = "dddccdbba";
	std::cout << firstUniqChar(s4) << std::endl;

	return 0;
}
