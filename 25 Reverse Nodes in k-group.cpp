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
        ListNode* reverseKGroup(ListNode* head, int k) {
            //reverse k nodes at a time
            //if we have less than k nodes, return the list as is
            if (!head || !head->next || k == 1) {
                return head;
            }
            
            int n = 0;

            ListNode* node = nullptr; //holds the node we last passed over when reversing
            ListNode* start = head; //holds the start of the entire list
            ListNode* pre = nullptr; //holds the end of the previous group
            ListNode* section_head = head; //holds the start of the current group, which ends up being the end after we reverse
            bool isStart = true;

            while(head->next) {
                n++;

                ListNode* temp = head->next;
                head->next = node;
                node = head;
                head = temp;

                if (n == k) {
                    if (isStart) { //first group
                        isStart = false;
                        start = node; //start is now the beginning of the first group we reversed
                    }

                    if (pre) { // connect previous group 
                        pre->next = node;
                    }
                    pre = section_head; //pre is now the end of the group we just reversed
                    node = nullptr;
                    //we don't connect to next group because we still need to reverse it 
                    section_head = head;
                    
                    n = 0;
                }
            }

            if (n+1 != k) { //the last group had less than k nodes, reverse it back
                ListNode* last = head; 
                if (node){
                    head = node; 
                    node = last; 
                }
                while (head->next) {
                    ListNode* temp = head->next;
                    head->next = node;
                    node = head;
                    head = temp;
                }
                //connect to previous group
                head->next = node;
                
            }
            else { //reverse last node of last group
                head->next = node;
            }

            if (pre) {
                pre->next = head;
            }
            else {
                start = head;
            }

            return start;
        }
};