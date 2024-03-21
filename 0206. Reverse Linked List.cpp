// Task: https://leetcode.com/problems/reverse-linked-list/

#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode* next = nullptr;
	ListNode* prev = nullptr;;

    while(head){
    	next = head->next;
        head->next = prev; 
        prev = head;
        head = next;
    }
    
	return prev;	
}

void printLL(ListNode* head) {
	ListNode* tmp = head;
	while (tmp) {
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void deleteLL(ListNode* head) {
	ListNode* toDelete = nullptr;
	while(head){
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
	head = nullptr;
}

int main() {
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
	printLL(l1);
	printLL(reverseList(l1));

    	deleteLL(l1);
    
	return 0;
}
