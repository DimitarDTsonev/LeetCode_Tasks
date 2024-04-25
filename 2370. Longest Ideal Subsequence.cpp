// Task : https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25

#include <iostream>
#include <string>
#include <vector>

static auto _ = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

int longestIdealString(std::string s, int k) {
	int size = s.size();
	int arr[26] = { 0 };
	std::vector<int> dp(size, 0);
	int curr;
	int low;
	int up;

	for (size_t i = 0; i < size; i++) {
		curr = s[i] - 'a';
		low = std::max(0, curr - k);
		up = std::min(25, curr + k);

		for (int j = low; j < up + 1; j++) {
			dp[i] = std::max(dp[i], arr[j] + 1);
		}
		arr[curr] = std::max(dp[i], arr[curr]);
	}
	int res = 0;

	for (int i : dp) {
		res = std::max(i, res);
	}

	return res;
}

int main() {
	// Example 1:
	std::cout << longestIdealString("acfgbd", 2) << '\n';

	// Example 2:
	std::cout << longestIdealString("abcd", 3) << '\n';

	return 0;
}
