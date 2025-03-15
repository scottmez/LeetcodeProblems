/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            Node* head2 = head;
            Node* copy = new Node(head->val);
            Node* copy2 = copy;
            map<Node*, Node*> nodeMap;
            nodeMap[head] = copy;
            while (head->next) {
                head = head->next;
                copy->next = new Node(head->val);
                copy = copy->next;
                nodeMap[head] = copy;
            }
            head = head2;
            while (head) {
                if (head->random) {
                    nodeMap[head]->random = nodeMap[head->random];
                }
                head = head->next;
            }
            return copy2;
        }
};