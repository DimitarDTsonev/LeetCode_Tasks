// Task : https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
	if (!head) {
		return nullptr;
	}
	ListNode* prev = head->next, * curr = head->next;
	ListNode ans(0, curr);
	int sum = 0;
	while (curr) {
		int x = curr->val;
		if (x != 0) sum += x;
		else {
			prev->val = sum;
			prev->next = curr->next;
			prev = prev->next;
			sum = 0;
		}
		curr = curr->next;
	}
	return ans.next;
}

void printLL(ListNode* ll) {
	ListNode* iter = ll;

	while (iter) {
		std::cout << iter->val << " ";
		iter = iter->next;
	}
	std::cout << '\n';
}

int main() {
	// Example 1: 
	ListNode* l1 = new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5,
		new ListNode(2, new ListNode(0))))))));
	printLL(l1);
	printLL(mergeNodes(l1));

	// Example 2: 
	ListNode* l2 = new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2,
		new ListNode(2, new ListNode(0))))))));
	printLL(l2);
	printLL(mergeNodes(l2));

	return 0;
}
