#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (list1 == nullptr) {
		return list2;
	}
	if (list2 == nullptr) {
		return list1;
	}

	ListNode* head;
	if (list1->val <= list2->val) {
		head = list1;
		list1 = list1->next;
	}
	else {
		head = list2;
		list2 = list2->next;
	}

	ListNode* current = head;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val <= list2->val) {
			current->next = list1;
			list1 = list1->next;
		}
		else {
			current->next = list2;
			list2 = list2->next;
		}
		current = current->next;
	}

	if (list1 != nullptr) {
		current->next = list1;
	}
	if (list2 != nullptr) {
		current->next = list2;
	}

	return head;
}

void printLL(ListNode* head) {
	ListNode* tmp = head;
	while (tmp) {
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

int main() {
	// Test:
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
	ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));

	printLL(l1);
	printLL(l2);

	ListNode* l3 = mergeTwoLists(l1, l2);
	printLL(l3);

	delete l3;
	l1 = l2 = l3 = nullptr;

	return 0;
}
