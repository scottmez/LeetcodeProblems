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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            //Regular reverse list
            /*
            ListNode* node = nullptr;

            while(head) {
                ListNode* temp = head->next;
                head->next = node;
                node = head;
                head = temp;
            }
            return node;
            */
            if (!head || left == right) {
               return head;
            }
            ListNode* front = head;
            ListNode* pre = nullptr;
            ListNode* post = nullptr;
            ListNode* section_tail = nullptr;
            ListNode* section_head = nullptr;

            while (head) {
                cout << head->val << endl;
                if (left == 2) {
                    pre = head;
                }
                else if (left == 1) {
                    section_head = head;
                }
                else if (right == 1) {
                    section_tail = head;
                    post = head->next;
                    break;
                }
                left--;
                right--;
                head = head->next;
            }
            
            head = section_head;

            ListNode* node = nullptr;

            while(head != post) {
                ListNode* temp = head->next;
                head->next = node;
                node = head;
                head = temp;
            }
            
            if (pre) {
                pre->next = section_tail;
            }
            else {
                front = section_tail;
            }
            
            section_head->next = post;

            return front;
        }
};