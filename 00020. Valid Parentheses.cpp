#include<iostream>
#include<stack>
#include<string>

bool balancedBrackets(std::string str) {
    std::stack<char> st;
    int i = 0, isBalanced = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            continue;
        }
        else {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
                i++;
                isBalanced++;
                continue;
            }

            if (str[i] == ')' && st.top() != '(') {
                return false;
            }
            if (str[i] == '}' && st.top() != '{') {
                return false;
            }
            if (str[i] == ']' && st.top() != '[') {
                return false;
            }

            if (st.top() == '(' && str[i] == ')') {
                st.pop();
                isBalanced--;
            }
            else if (st.top() == '{' && str[i] == '}') {
                st.pop();
                isBalanced--;
            }
            else if (st.top() == '[' && str[i] == ']') {
                st.pop();
                isBalanced--;
            }
        }
        i++;
    }
    return !isBalanced;
}

int main() {
    std::string str("(})");

    std::cout << balancedBrackets(str);
}
