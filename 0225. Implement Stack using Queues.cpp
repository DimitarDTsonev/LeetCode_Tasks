#include<iostream>
#include<queue>

class MyStack {
private:
	std::queue<int> q1;
	std::queue<int> q2;

public:
	MyStack() {

	}

	void push(int toPush) {
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(toPush);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
	}

	int pop() {
		int toReturn = q1.front();
		
		q1.pop();
		return toReturn;
	}

	int top()  {
		return q1.front();
	}

	bool empty()  {
		return q1.empty();
	}
};

int main() {
	MyStack st1;

	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);


	for (size_t i = 0; i < 5; i++) {
		std::cout << st1.top() << " ";
		st1.pop();
	}
    std::cout << std::endl;

	MyStack* st2 = new MyStack();
	st2->push(5);
	st2->push(4);
	st2->push(3);
	st2->push(2);
	st2->push(1);

    for (size_t i = 0; i < 5; i++) {
		std::cout << st2->top() << " ";
		st2->pop();
	}

	delete st2;
	return 0;
}
