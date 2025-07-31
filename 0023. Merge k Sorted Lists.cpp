// Task : https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <iostream> 
#include <vector>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
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
    } else {
        head = list2;
        list2 = list2->next;
    }

    ListNode* current = head;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
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

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
        
    while (lists.size() > 1) {
        int mergedSize = (lists.size() + 1) / 2;
        std::vector<ListNode*> merged;

        for (int i = 0; i < mergedSize; i++) {
            int ind1 = i * 2;
            int ind2 = i * 2 + 1;
            ListNode* l1 = lists[ind1];
            ListNode* l2 = (ind2 < lists.size() ? lists[ind2] : nullptr);
            merged.push_back(mergeTwoLists(l1, l2));
        }
        lists = merged;
    }

    return lists[0];
}
