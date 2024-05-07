// Task : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

#include <iostream>
#include <stack>

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* doubleIt(ListNode* head) {
	std::stack<int> st;

	while (head != nullptr) {
		st.push(head->val);
		head = head->next;
	}

	ListNode* tail = nullptr;
	int res = 0;

	while (!st.empty() || res != 0) {
		tail = new ListNode(0, tail);

		if (!st.empty()) {
			res += st.top() * 2; 
			st.pop();
		}
		tail->val = res % 10;
		res /= 10;
	}

	return tail;
}

void printLL(ListNode* head) {
	ListNode* iter = head;
	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}
	std::cout << '\n';
}

void deleteLL(ListNode* head) {
	ListNode* iter = head;

	while (head) {
		iter = head;
		head = head->next;
		delete[] iter;
	}
}

int main() {
	// Example 1:
	ListNode* l1 = new ListNode(1, new ListNode(8, new ListNode(9)));
	printLL(doubleIt(l1));

	// Example 2:
	ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9)));
	printLL(doubleIt(l2));

	deleteLL(l1);
	l1 = nullptr;
	deleteLL(l2);
	l2 = nullptr;

	return 0;
}
