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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head->next) {
                return nullptr;
            }
            vector<ListNode*> nodes;
            while (head) {
                nodes.push_back(head);
                head = head->next;
            }
            if (n == nodes.size()) {
                return nodes[1];
            }
            if (n == 1) {
                nodes[nodes.size() - 2]->next = nullptr;
                return nodes[0];
            }
            int nodeToRemove = nodes.size() - n;
            nodes[nodeToRemove - 1]->next = nodes[nodeToRemove + 1];
            return nodes[0];
        }
};