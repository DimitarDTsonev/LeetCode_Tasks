// Task: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include<iostream>
#include<vector>
#include<string>
#include<stack>

int evalRPN(std::vector<std::string>& tokens) {
	std::stack<std::string> mystack;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] != "+" && tokens[i] != "/" && tokens[i] != "*" && tokens[i] != "-") {
			mystack.push(tokens[i]);
		}
		else {
			int a = stoi(mystack.top());
			mystack.pop();
			int b = stoi(mystack.top());
			mystack.pop();
			int value;
			if (tokens[i] == "+") {
				value = a + b;
			}
			else if (tokens[i] == "*") {
				value = a * b;
			}
			else if (tokens[i] == "/") {
				value = b / a;
			}
			else {
				value = b - a;
			}
			mystack.push(std::to_string(value));
		}
	}

	return stoi(mystack.top());
}

int main() {
	// Example 1:
	std::vector<std::string> vec1 = { "2", "1", "+", "3", "*" };
	std::cout << evalRPN(vec1) << "\n";

	// Example 2:
	std::vector<std::string> vec2 = { "4", "13", "5", "/", "+" };
	std::cout << evalRPN(vec2) << "\n";

	// Example 3:
	std::vector<std::string> vec3 = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	std::cout << evalRPN(vec3) << "\n";

	return 0;
}
