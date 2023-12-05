#include<iostream>
#include<stack>

class MyQueue {
public:
    std::stack<int> st1, st2;

    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (st1.empty() == false) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x = st2.top();
        st2.pop();

        return x;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return  st2.top();
    }

    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

int main() {
    MyQueue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    while (!q1.empty()) {
        std::cout << q1.peek() << " ";
        q1.pop();
    }
    std::cout << std::endl;

    MyQueue* q2 = new MyQueue();
    q2->push(5);
    q2->push(4);
    q2->push(3);
    q2->push(2);
    q2->push(1);

    while (!q2->empty()) {
        std::cout << q2->peek() << " ";
        q2->pop();
    }

    delete q2;

    return 0;
}
