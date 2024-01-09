// Task: https://leetcode.com/problems/ransom-note/

#include<unordered_map>
#include<iostream>
#include<string>

// Solution with hashmaps:
bool canConstruct(std::string ransomNote, std::string magazine) {
	std::unordered_map<char, unsigned> magazineLetters;

	for (size_t i = 0; i < magazine.size(); i++) {
		char ch = magazine[i];

		if (magazineLetters.find(ch) != magazineLetters.end()) {
			magazineLetters[ch]++;
		}
		else {
			magazineLetters[ch] = 1;
		}
	}

	for (size_t i = 0; i < ransomNote.size(); i++) {
		char ch = ransomNote[i];
		if (magazineLetters[ch] == 0) {
			return false;
		}
		else {
			--magazineLetters[ch];
		}
	}
	return true;
}

// Solution using the ASCII codes:     --> faster solution! 
bool canConstruct(std::string ransomNote, std::string magazine) {
    int frequency[26] = {0};
    int charAscii = 97;
    
    for (int i = 0; i < magazine.size(); i++) {
        frequency[magazine[i] - charAscii]++;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
          if (--frequency[ransomNote[i] - charAscii] < 0) {
              return false;
          }
    }
    return true;
}

int main() {
	// Example 1:
	std::string ransomNote1("a");
	std::string magazine1("b");
	std::cout << canConstruct(ransomNote1, magazine1) << std::endl;

	// Example 2:
	std::string ransomNote2("aa");
	std::string magazine2("ab");
	std::cout << canConstruct(ransomNote2, magazine2) << std::endl;

	// Example 3:
	std::string ransomNote3("aa");
	std::string magazine3("aab");
	std::cout << canConstruct(ransomNote3, magazine3) << std::endl;

	return 0;
}
