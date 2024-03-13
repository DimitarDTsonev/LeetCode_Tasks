// Task: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

std::unordered_map<char, std::string> keypad = {
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"}
};

void generateCombinations(std::string digits, int index, std::string current, std::vector<std::string>& res) {
	if (index == digits.size()) {
		if (!current.empty())
			res.push_back(current);
		return;
	}

	char digit = digits[index];
	std::string letters = keypad[digit];

	for (char letter : letters) {
		generateCombinations(digits, index + 1, current + letter, res);
	}
}

std::vector<std::string> letterCombinations(std::string digits) {
	std::vector<std::string> res;
	
	if (digits.empty()) {
		return res;
	}
	generateCombinations(digits, 0, "", res);
	
	return res;
}

void printVec(std::vector<std::string> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	printVec(letterCombinations("23"));

	// Example 2:
	printVec(letterCombinations(""));

	// Example 2:
	printVec(letterCombinations("2"));

	return 0;
}
