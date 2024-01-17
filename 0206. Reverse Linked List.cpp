// Task:
#include<iostream>
#include<stack>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	std::stack<int> st;
	ListNode* reversed = new ListNode(), * holder = reversed;
	while (head) {
		st.push(head->val);
		head = head->next;
	}

	while (st.size() != 0) {
		if (st.size() != 1) {
			reversed->val = st.top();
			reversed->next = new ListNode();
			reversed = reversed->next;
			st.pop();
		}
		else {
			break;
		}
	}
	reversed->val = st.top();

	return holder;
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
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
	printLL(l1);
	printLL(reverseList(l1));

    delete l1;
    l1 = nullptr;
    
	return 0;
}
