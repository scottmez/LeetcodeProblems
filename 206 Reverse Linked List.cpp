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
    ListNode* reverseList(ListNode* head) {
        int *arr = new int[5000];
        int n = 0;
        while (head != NULL) {
            arr[n] = head->val;
            head = head->next;
            n++;
        }
        if (n > 0) {
            head = new ListNode(arr[n-1]);
        }
        ListNode *curr = head;
        for (size_t i = 1; i < n; i++) {
            curr->next = new ListNode(arr[n-1-i]);
            curr = curr->next;
        }
        delete[] arr;
        return head;
    }
};