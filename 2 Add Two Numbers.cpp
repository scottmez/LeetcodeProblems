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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode();
            ListNode* head = result;
            int carry = 0;
            int sum;
            while (l1 || l2 || carry != 0) {
                sum = carry;

                if (l1) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    sum += l2->val;
                    l2 = l2->next;
                }

                carry = sum / 10;
                result->val = sum % 10;
                
                //only if we have a next node do we add it
                if (l1 || l2 || carry != 0) {
                    result->next = new ListNode();
                    result = result->next;
                }
            }

            return head;
        }
    };