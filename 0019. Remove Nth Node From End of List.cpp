#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* ptr = head;
    int counter = 0;
    while (ptr != nullptr) {
        counter++;
        ptr = ptr->next;
    }
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    if (counter - n == 0) {
        head = head->next;
        return head;
    }
    ListNode* temp = head;
    ListNode* slow = head;
    for (int i = 0; i < counter - n; i++) {
        slow = temp;
        temp = temp->next;
    }
    slow->next = temp->next;
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
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    printLL(l1);
    removeNthFromEnd(l1, 2);
    printLL(l1);

    ListNode* l2 = new ListNode(1);
    printLL(l2);
    removeNthFromEnd(l2, 1);
    printLL(l2);

    ListNode* l3 = new ListNode(1, new ListNode(2, nullptr));
    printLL(l3);
    removeNthFromEnd(l1, 1);
    printLL(l3);


    delete l1;
    delete l2;
    delete l3;
    l1 = l2 = l3 = nullptr;
    
    return 0;
}
