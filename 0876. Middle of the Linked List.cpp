// Task: https://leetcode.com/problems/middle-of-the-linked-list/description/

#include<iostream>

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* middleNode(ListNode* head) {
	ListNode* fast = head;

	while (fast && fast->next) {
		head = head->next;
		fast = fast->next->next;
	}
	return head;
}

void deleteLL(ListNode* head){
	ListNode* toDelete = nullptr;
	while(head){
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
	head = nullptr;
	toDelete = nullptr;
}

int main() {
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
	printLL(l1);

	std::cout << middleNode(l1)->val;

	delete l1;
	l1 = nullptr;

	return 0;
}
