// Task: https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLL(ListNode* head) {
	ListNode* iter = head;

	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}
	std::cout << "\n";
}

void deleteLL(ListNode* head) {
	ListNode* toDelete;
	while (head) {
		toDelete = head;
		head = head->next;
		delete[] toDelete;
	}
	head = nullptr;
}

ListNode* swapPairs(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}

	ListNode* iterNext = head->next;
	head->next = swapPairs(iterNext->next);
	iterNext->next = head;

	return iterNext;
}

int main() {
	// Example 1:
	ListNode* ll1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	printLL(swapPairs(ll1));
	deleteLL(ll1);

	// Example 2:
	ListNode* ll2 = nullptr;
	printLL(swapPairs(ll2));
	deleteLL(ll2);

	// Example 3:
	ListNode* ll3 = new ListNode(1);
	printLL(swapPairs(ll3));
	deleteLL(ll3);

	return 0;
}
