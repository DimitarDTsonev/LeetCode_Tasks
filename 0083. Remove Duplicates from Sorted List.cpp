// Task: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (!head) {
		return nullptr;
	}

	ListNode* iter = head;
	ListNode* toDelete = nullptr;

	while (iter->next) {
		if (iter->val == iter->next->val) {
			toDelete = iter->next;

			if (iter->next->next) {
				iter->next = iter->next->next;
			}
			else {
				iter->next = nullptr;
			}
			
			delete toDelete;
			toDelete = nullptr;
			continue;
		}
		iter = iter->next;
	}
	return head;
}

void printLL(ListNode* head) {
	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	ListNode* l1 = new ListNode(1, new ListNode(1, new ListNode(2)));
	printLL(l1);
	deleteDuplicates(l1);
	printLL(l1);

	// Example 2:
	ListNode* l2 = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
	printLL(l2);
	deleteDuplicates(l2);
	printLL(l2);

	return 0;
}
