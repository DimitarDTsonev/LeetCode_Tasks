// Task: https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04

#include <iostream>
#include <unordered_map>

std::string minWindow(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> map;
    for (char ch : t) {
        map[ch]++;
    }

    int targetCount = map.size();
    int currentCount = 0;

    int start = 0, end = 0;
    int minLength = INT_MAX;
    int minStart = 0;

    while (end < s.length()) {
        if (map.find(s[end]) != map.end()) {
            map[s[end]]--;
            if (map[s[end]] == 0) {
                currentCount++;
            }
        }

        while (currentCount == targetCount) {
            if (end - start < minLength) {
                minLength = end - start;
                minStart = start;
            }

            if (map.find(s[start]) != map.end()) {
                map[s[start]]++;
                if (map[s[start]] > 0) {
                    currentCount--;
                }
            }

            start++;
        }
        end++;
    }

    return (minLength == INT_MAX) ? "" : s.substr(minStart, minLength + 1);
}

int main() {
    // Example 1:
	std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;

	// Example 2:
	std::cout << minWindow("a", "a") << std::endl;

	// Example 3:
	std::cout << minWindow("a", "aa") << std::endl;

	return 0;
}
