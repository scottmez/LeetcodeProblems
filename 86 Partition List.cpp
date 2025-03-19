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
        ListNode* partition(ListNode* head, int x) {
            ListNode* less = nullptr;
            ListNode* gte = nullptr;
            ListNode* lessHead = nullptr;
            ListNode* gteHead = nullptr;
            while (head) {
                if (head->val < x) {
                    if (!less) {
                        less = head;
                        lessHead = head;
                    }
                    else {
                        less->next = head;
                        less = less->next;
                    }
                }
                else {
                    if (!gte) {
                        gte = head;
                        gteHead = head;
                    }
                    else {
                        gte->next = head;
                        gte = gte->next;
                    }
                }
                head = head->next;
            }
            if (less) {
                less->next = gteHead;
            }
            if (gte) {
                gte->next = nullptr;
            }
            if (lessHead) {
                return lessHead;
            }
            return gteHead;
        }
};