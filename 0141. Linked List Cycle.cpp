// Task: https://leetcode.com/problems/linked-list-cycle/

#include<iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* _next) : val(x), next(_next){}
};

bool hasCycle(ListNode *head) {
    ListNode* slow = head, * fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
    return false;
}

int main() {
    // Example 1:
    ListNode l4(-4);
    ListNode l3(0, &l4);
    ListNode l2(2, &l3);
    ListNode l1(3, &l2);
    l4.next = &l2;

    std::cout << hasCycle(&l1) << std::endl;

    // Example 2:
    ListNode ll2(2);
    ListNode ll1(1, &ll2);
    ll2.next = &ll1;
    
    std::cout << hasCycle(&ll1) << std::endl;

    // Example 3:
    ListNode lll(1);
  
    std::cout << hasCycle(&lll) << std::endl;

    return 0;
}
