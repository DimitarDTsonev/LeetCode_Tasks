#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* tmp1 = list1;
    ListNode* tmp2 = list1;
    ListNode* tmp3 = list1;
    ListNode* afterRemove = NULL;
    ListNode* prev = NULL;
    
    int firstCount = 0;
    
    while (tmp1 != NULL) {
        if (firstCount == b) {
            afterRemove = tmp1->next;
            break;
        }
    
        firstCount++;
        tmp1 = tmp1->next;
    }
    
    int secondCount = 0;
    
    while (tmp2 != NULL) {
        if (secondCount == a - 1) {
            tmp2->next = list2;
            break;
        }
        secondCount++;
        tmp2 = tmp2->next;
    }
    
    while (tmp3 != NULL) {
        prev = tmp3;
        tmp3 = tmp3->next;
    }
    
    prev->next = afterRemove;
    
    return list1;
}

int main() {
	ListNode l6(5, nullptr);
	ListNode l5(4, &l6);
	ListNode l4(3, &l5);
	ListNode l3(2, &l4);
	ListNode l2(1, &l3);
	ListNode l1(0,&l2);

	ListNode t3(12, nullptr);
	ListNode t2(11, &t3);
	ListNode t1(10, &t2);

	mergeInBetween(&l1, 3, 4, &t1);
    ListNode* tmp = &l1;
    while (tmp) {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }

	return 0;
}