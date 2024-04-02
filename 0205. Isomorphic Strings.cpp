// Task: https://leetcode.com/problems/isomorphic-strings/description/?envType=daily-question&envId=2024-04-02

#include <iostream>
#include <string>
#include <vector>

bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) {
        return false;
    }
    std::vector<int> indexS(128, -1);
    std::vector<int> indexT(128, -1);
    unsigned len = s.length();

    for (int i = 0; i < len; i++) {
        if (indexS[s[i]] != indexT[t[i]]) {
            return false;
        }
        indexS[s[i]] = indexT[t[i]] = i;
    }

    return true;
}

int main() {
	// Example 1:
	std::cout << isIsomorphic("egg", "add") << "\n";

	// Example 2:
	std::cout << isIsomorphic("foo", "bar") << "\n";

	// Example 3: 
	std::cout << isIsomorphic("paper", "title") << "\n";

	return 0;
}
