// Task: https://leetcode.com/problems/min-stack

#include<iostream>
#include<vector>

class MinStack {
public:
    std::vector<long long> st;
    long long minElem = INT_MAX;
    MinStack() {

    }

    void push(int val) {
        st.push_back(val);
        minElem = val < minElem ? val : minElem;
    }

    void pop() {
        if (st.back() == getMin()) {
            st.pop_back();
            minElem = st.empty() ? INT_MAX : *std::min_element(st.begin(), st.end());
        }
        else {
            st.pop_back();
        }
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return minElem;
    }
};

int main() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); // return -3
    minStack->pop();
    minStack->top();    // return 0
    minStack->getMin(); // return -2

    return 0;
}
