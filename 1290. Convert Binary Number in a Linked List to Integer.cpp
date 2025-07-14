// Task : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14

#include<iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

int getDecimalValue(ListNode* head) {
    int res = 0;

    while (head != nullptr) {
        res = (res << 1) | head->val;
        head = head->next;
    }

    return res;
}  

int main() {
    // Example 1:
    ListNode* head = new ListNode(1, new ListNode(0, new ListNode(1)));
    std::cout << getDecimalValue(head) << '\n';
    
    return 0;
}
