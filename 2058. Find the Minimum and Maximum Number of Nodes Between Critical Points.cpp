// Task : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05

#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};

std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
	std::vector<int> res(2, -1);

	if (!head || !head->next || !head->next->next) {
		return res;
	}
	ListNode* pre = head;
	ListNode* cur = head->next;
	int prePosition = -1;
	int curPosition = -1;
	int firstPosition = -1;
	int position = 0;

	while (cur->next) {
		if ((cur->val < pre->val && cur->val < cur->next->val) || (cur->val > pre->val && cur->val > cur->next->val)) {
			prePosition = curPosition;
			curPosition = position;

			if (firstPosition == -1) {
				firstPosition = position;
			}
			if (prePosition != -1) {
				if (res[0] == -1) {
					res[0] = curPosition - prePosition;
				}
				else {
					res[0] = std::min(res[0], curPosition - prePosition);
				}
				res[1] = position - firstPosition;
			}
		}
		position++;
		pre = cur;
		cur = cur->next;
	}
	return res;
}

void printLL(ListNode* head) {
	ListNode* iter = head;
	std::cout << "Linked List -> ";
	while (iter->next) {
		std::cout << iter->val << " -> ";
		iter = iter->next;
	}
	std::cout << iter->val << "\n";
}

void printVec(const std::vector<int>& vec) {
	std::cout << "Vector : ";
	for (size_t i = 0; i < vec.size() - 1; i++) {
		std::cout << vec[i] << ", ";
	}
	std::cout << vec[vec.size() - 1] << '\n';
}

int main() {
	// Example 1:
	ListNode* l1 = new ListNode(3, new ListNode(1));
	printLL(l1);
	printVec(nodesBetweenCriticalPoints(l1));

	// Example 2:
	ListNode* l2 = new ListNode(5, new ListNode(3, new ListNode(1, new ListNode(2, new ListNode(5,
		new ListNode(1, new ListNode(2)))))));
	printLL(l2);
	printVec(nodesBetweenCriticalPoints(l2));

	// Example 3:
	ListNode* l3 = new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(3,
		new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(7)))))))));
	printLL(l3);
	printVec(nodesBetweenCriticalPoints(l3));

	return 0;
}
