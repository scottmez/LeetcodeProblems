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
        ListNode* rotateRight(ListNode* head, int k) {
            //plan:
            //count nodes "numNodes"
            // k = k % numNodes
            //

            if (!head || !head->next || k == 0) {
                return head;
            }

            int numNodes = 1;

            ListNode* begin = head;

            while (head->next) {
                numNodes++;
                head = head->next;
            }

            k = k % numNodes;
            if (k == 0) {
                return begin;
            } 
            int breakpoint = numNodes - k;

            head = begin;

            for (int i = 1; i < breakpoint; i++) {
                head = head->next;
            }

            ListNode* newTail = head;
            ListNode* newHead = head->next;

            newTail->next = nullptr;
            head = newHead;
            while (head->next) {
                head = head->next;
            }
            head->next = begin;

            return newHead;

        }
};