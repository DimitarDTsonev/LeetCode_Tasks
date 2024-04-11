
// Task : https://leetcode.com/problems/remove-k-digits/?envType=daily-question&envId=2024-04-11

#include <iostream>
#include <string>

std::string removeKdigits(std::string num, int k) {
	if (k == num.size()) {
		return "0";
	}

	std::string res("");
	std::vector<char> st;

	for (int i = 0; i < num.size(); ++i) {
		while (k > 0 && !st.empty() && st.back() > num[i]) {
			st.pop_back();
			--k;
		}
		st.push_back(num[i]);
	}

	while (k-- > 0) {
		st.pop_back();
	}

	for (const char ch : st) {
		if (ch == '0' && res.empty()) {
			continue;
		}
		res += ch;
	}

	return res.empty() ? "0" : res;
}

int main() {
	// Example 1:
	std::cout << removeKdigits("1432219", 3) << '\n';

	// Exqmple 2:
	std::cout << removeKdigits("10200", 1) << '\n';

	// Exqmple 3:
	std::cout << removeKdigits("10", 2) << '\n';

	return 0;
}
