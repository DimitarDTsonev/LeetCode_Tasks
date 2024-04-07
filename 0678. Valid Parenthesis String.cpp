// Task: https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

#include <iostream>
#include <string>

bool checkValidString(std::string s) {
    int lCount = 0;
    int rCount = 0;

    for (char ch : s) {
        if (ch == '(') {
            lCount++;
            rCount++;
        } else if (ch == ')') {
                lCount--;
                rCount--;
        } else if(ch == '*'){
            lCount--;
            rCount++;
        }

        if (rCount < 0) {
            return false;
        }

        if (lCount < 0) {
            lCount = 0;
        }
    }

    return lCount == 0;
}

int main() {
	// Example 1:
	std::cout << checkValidString("()") << "\n";

	// Example 2: 
	std::cout << checkValidString("(*)") << "\n";

	// Example 3:
	std::cout << checkValidString("(*))") << "\n";

	return 0;
}
