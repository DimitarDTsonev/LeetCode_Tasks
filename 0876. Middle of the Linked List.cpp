ListNode* middleNode(ListNode* head) {
	ListNode* fast = head;

	while (fast && fast->next) {
		head = head->next;
		fast = fast->next->next;
	}
	return head;
}

int main() {
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
	printLL(l1);

	std::cout << middleNode(l1)->val;

	delete l1;
	l1 = nullptr;

	return 0;
}
