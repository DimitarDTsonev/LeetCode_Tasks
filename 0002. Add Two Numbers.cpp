// Task: https://leetcode.com/problems/add-two-numbers/

#include<iostream>
#include<string>

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int _val) : val(_val), next(nullptr) {}
	ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(0);
	ListNode* tail = dummyHead;
	bool carry = 0;

	while (l1 != nullptr || l2 != nullptr || carry != 0) {
		int digit1 = (l1 != nullptr) ? l1->val : 0;
		int digit2 = (l2 != nullptr) ? l2->val : 0;

		int sum = digit1 + digit2 + carry;
		int digit = sum % 10;
		carry = sum / 10;

		ListNode* newNode = new ListNode(digit);
		tail->next = newNode;
		tail = tail->next;

		l1 = (l1 != nullptr) ? l1->next : nullptr;
		l2 = (l2 != nullptr) ? l2->next : nullptr;
	}

	ListNode* result = dummyHead->next;
	delete dummyHead;
	return result;
}

void printLL(ListNode* head) {
	ListNode* iter = head;
	while (iter) {
		std::cout << iter->val;
		iter = iter->next;
	}
}

int main() {
	// Example 1:
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3,nullptr)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4,nullptr)));
	ListNode* l3 = addTwoNumbers(l1, l2);	

	printLL(l1);
	std::cout << " + ";
	printLL(l2);
	std::cout << " = ";
	printLL(l3);
	std::cout << std::endl;

	// Example 2:
	ListNode* l4 = new ListNode();
	ListNode* l5 = new ListNode();
	ListNode* l6 = addTwoNumbers(l4, l5);

	printLL(l4);
	std::cout << " + ";
	printLL(l5);
	std::cout << " = ";
	printLL(l6);
	std::cout << std::endl;

	// Example 3:
	ListNode* l7 = new ListNode(9, new	ListNode(9, new	ListNode(9, new ListNode(9, 
		new ListNode(9, new ListNode(9, new ListNode(9, nullptr)))))));
	ListNode* l8 = new ListNode(9, new	ListNode(9, new ListNode(9, new ListNode(9, nullptr))));
	ListNode* l9 = addTwoNumbers(l7, l8);

	printLL(l7);
	std::cout << " + ";
	printLL(l8);
	std::cout << " = ";
	printLL(l9);
	std::cout << std::endl;

	return 0;
}
