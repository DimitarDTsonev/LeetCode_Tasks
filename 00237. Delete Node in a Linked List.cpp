#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *_next) : val(x), next(_next){}
};

void deleteNode(ListNode* node) {
    while(node->next->next != nullptr){
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = nullptr;
}

void printLL(ListNode *head){
    while(head != nullptr){
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(){
    // Example 1:
    ListNode l4(9);
    ListNode l3(1, &l4);
    ListNode l2(5, &l3);
    ListNode l1(4, &l2);

    deleteNode(&l2);
    printLL(&l1);

    // Example 2:
    ListNode ll4(9);
    ListNode ll3(1, &ll4);
    ListNode ll2(5, &ll3);
    ListNode ll1(4, &ll2);

    deleteNode(&ll3);
    printLL(&ll1);

    return 0;
}