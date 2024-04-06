// Task: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06

#include <iostream>
#include <string>
#include <deque>

std::string minRemoveToMakeValid(std::string s) {
    std::string temp;
    int currentCounter = 0;
    int size = s.size();

    for (char ch : s) {
        currentCounter += (ch == '(') - (ch == ')');
        if (currentCounter >= 0) {
            temp.push_back(ch);
        }
        else {
            currentCounter = 0;
        }
    }

    currentCounter = 0;
    std::deque<char> res;
    char ch = ' ';

    for (int i = temp.size() - 1; i >= 0; i--) {
        ch = temp[i];
        currentCounter += (ch == '(') - (ch == ')');
        
        if (currentCounter <= 0) { 
            res.push_front(ch); 
        }
        else {
            currentCounter = 0;
        }
    }
    
    return std::string(res.begin(), res.end());
}

int main() {
	// Example 1:
	std::cout << minRemoveToMakeValid("lee(t(c)o)de)") << "\n";

	// Example 2:
	std::cout << minRemoveToMakeValid("a)b(c)d") << "\n";

	// Example 3:
	std::cout << minRemoveToMakeValid("))((") << "\n";

	return 0;
}
