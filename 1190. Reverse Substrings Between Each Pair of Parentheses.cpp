// Task : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

#include <iostream>
#include <string>
#include <stack>

std::string reverseParentheses(std::string s) {
	std::stack<char> stack;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (c == ')') {
			std::string rev = "";
			while (!stack.empty() && stack.top() != '(') {
				rev += stack.top();
				stack.pop();
			}
			if (!stack.empty()) {
				stack.pop();
			}
			for (int j = 0; j < rev.length(); j++) {
				stack.push(rev[j]);
			}
		}
		else {
			stack.push(c);
		}
	}

	std::string result(stack.size(), 'a');
	int i = stack.size() - 1;
	while (!stack.empty()) {
		result[i] = stack.top();
		i--;
		stack.pop();
	}
	return result;
}

int main() {
	// Example 1:
	std::cout << reverseParentheses("(abcd)") << '\n';

	// Example 2:
	std::cout << reverseParentheses("(u(love)i)") << '\n';

	// Example 3:
	std::cout << reverseParentheses("(ed(et(oc))el)");

	return 0;
}
