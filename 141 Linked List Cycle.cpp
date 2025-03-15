/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            //idea is to have one pointer go twice as fast as the other
            //if there is a cycle, they will eventually meet
            //if there is no cycle, the faster pointer will hit the end of the list
            ListNode* a = head; 
            ListNode* b = head;
            while (b && b->next) {
                a = a->next;
                b = b->next->next;
                if (a == b) {
                    return true;
                }
            }
            return false;
        }
    };