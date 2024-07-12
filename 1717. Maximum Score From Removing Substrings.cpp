// Task : https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12

#include <iostream>
#include <string>

int helper(std::string& s, std::string target, int c) {
	int i = -1;
	int ans = 0;

	for (int j = 0; j < s.size(); j++) {
		if (i >= 0 && s[i] == target[0] && s[j] == target[1]) {
			i--;
			ans += c;
		}
		else {
			s[++i] = s[j];
		}
	}
	s = s.substr(0, i + 1);

	return ans;
}

int maximumGain(std::string s, int x, int y) {
	std::string ab = "ab";
	std::string ba = "ba";

	if (x < y) {
		std::swap(x, y);
		swap(ab, ba);
	}

	return helper(s, ab, x) + helper(s, ba, y);
}

int main() {
	// Example 1 :
	std::cout << maximumGain("cdbcbbaaabab", 4, 5) << '\n';

	// Example 1 :
	std::cout << maximumGain("aabbaaxybbaabb", 5, 4) << '\n';

	return 0;
}
