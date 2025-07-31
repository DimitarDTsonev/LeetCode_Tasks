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

void printList(ListNode* head) {
    ListNode* iter = head;
    while (iter) {
        std::cout << iter->val << " ";
        iter = iter->next;
    }
    std::cout << '\n';
}

int main() {
    // Example 1:
    ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* list3 = new ListNode(2, new ListNode(6)));
    std::vector<ListNode*> vec1;
    vec1.push_back(list1);
    vec1.push_back(list2);
    vec1.push_back(list3);
    ListNode* res1 = mergeKLists(vec1);
    printList(res1);

    // Example 2:
    std::vector<ListNode*> vec2;
    ListNode* res2 = mergeKLists(vec2);
    printList(res2);
    
    // Example 3:
    ListNode* list4 = new ListNode();
    std::vector<ListNode*> vec3;
    vec2.push_back(list4);
    ListNode* res3 = mergeKLists(vec2);
    printList(res3);
    
    return 0;
}
