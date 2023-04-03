/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* listMerged = NULL;
        if (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                listMerged = list1;
                list1 = list1->next;
            }
            else {
                listMerged = list2;
                list2 = list2->next;
            }
        }
        else if (list1 != NULL) {
            listMerged = list1;
            list1 = list1->next;
        }
        else if (list2 != NULL) {
            listMerged = list2;
            list2 = list2->next;
        }
        else {
            return NULL;
        }
        ListNode* front = listMerged;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                listMerged->next = list1;
                listMerged = listMerged->next;
                list1 = list1->next;
            }
            else {
                listMerged->next = list2;
                listMerged = listMerged->next;
                list2 = list2->next;
            }
        }
        if (list1 != NULL) 
            listMerged->next = list1;
        else if (list2 != NULL) 
            listMerged->next = list2;
        return front;
    }
};