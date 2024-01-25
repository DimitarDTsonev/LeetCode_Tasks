// Task: https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25

#include<iostream>
#include<string>
#include<vector>

int LCS(std::string s1, std::string s2) {
	std::vector<int> dp(s1.length() + 1, 0);

	for (int i = 1; i <= s2.length(); i++) {
		int prev = 0;
		for (int j = 1; j <= s1.length(); j++) {
			int temp = dp[j];
			if (s1[j - 1] == s2[i - 1]) {
				dp[j] = prev + 1;
			}
			else {
				dp[j] = std::max(dp[j - 1], dp[j]);
			}
			prev = temp;
		}
	}
	return dp[s1.length()];
}

int longestCommonSubsequence(std::string text1, std::string text2) {
	if (text1.length() < text2.length()) {
		return LCS(text1, text2);
	}
	return LCS(text2, text1);
}

int main() {
	// Example 1:
	std::string s1 = "abcde";
	std::string s2 = "ace";

	std::cout << longestCommonSubsequence(s1, s2) << std::endl;

	// Example 2:
	std::string s3 = "abc";
	std::string s4 = "abc";

	std::cout << longestCommonSubsequence(s3, s4) << std::endl;

	// Example 3:
	std::string s5 = "adc";
	std::string s6 = "def";

	std::cout << longestCommonSubsequence(s5, s6) << std::endl;

	return 0;
}
