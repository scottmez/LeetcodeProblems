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
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode* pre = nullptr; //holds the node seen most recently that is not a duplicate
            ListNode* start = head; //holds the start of the list
            ListNode* prev = nullptr; //holds the node before the current node (contains a duplicate)
            ListNode* post = nullptr; //holds the node after the duplicates
            bool stateAccepting = true;
            while (head->next) {
                //check if the next node is a duplicate
                if (head->next->val != head->val) {
                    if(stateAccepting && pre == nullptr) {
                        start = head;
                        pre = head;
                    }
                    else if(stateAccepting) {
                        pre->next = post;
                        pre = post;
                    }
                    else {
                        stateAccepting = true;
                    }
                    post = head->next; 
                } 
                else {
                    stateAccepting = false;
                }
                prev = head;
                head = head->next;
            }

            if (prev->val == head->val) {
                if (pre) {
                    pre->next = nullptr;
                }
                else {
                    return nullptr;
                }
            }
            else {
                if (pre) {
                    pre->next = head;
                }
                else {
                    return head;
                }
            }

            return start;
        }
};