// Task: https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<string>

std::string mergeAlternately(std::string word1, std::string word2) {
	int l1 = word1.length(), l2 = word2.length();
	
	std::string toReturn;
	for (size_t i = 0; i < std::min(l1, l2); ++i) {
		toReturn.push_back(word1[i]);
		toReturn.push_back(word2[i]);
	}
	if (l1 > l2) {
		toReturn.append(word1.substr(l2, l1 - l2));
	}
	else {
		toReturn.append(word2.substr(l1, l2 - l1));
	}

	return toReturn;
}

int main() {
    // Example 1:
    std::cout << mergeAlternately("abc", "pqr") << "\n";

    // Example 2:
    std::cout << mergeAlternately("ab", "pqrs") << "\n";

    // Example 3:
    std::cout << mergeAlternately("abcd", "pq") << "\n";

	return 0;
}
