int maxDepth(std::string str) {
    int counter = 0, currCounter = 0;
    std::stack<char> st;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(str[i]);
            ++currCounter;
        }
        if (str[i] == ')') {
            st.pop();
            if (st.empty()) {
                if (currCounter > counter) {
                    counter = currCounter;
                }
                currCounter = 0;
            }
            else {
                if (currCounter > counter) {
                    counter = currCounter;
                }
                --currCounter;
            }
        }
    }

    if (!st.empty()) {
        return 0;
    }
    return counter;
}

int main() {
    // Example 1:
    std::string str{ "(1+(2*3)+((8)/4))+1" };
    // Example 2:
    std::string str1{ "(1)+((2))+(((3)))" };

    std::cout << maxDepth(str) << std::endl;
    std::cout << maxDepth(str1) << std::endl;

    return 0;
}
