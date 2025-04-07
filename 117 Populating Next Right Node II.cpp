/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            //basic idead I have is to do a BFS traversal
            //in a BFS we store the nodes in a queue
            if (!root) {
                return root;
            }
            int depth = 1;
            queue<pair<Node*, int>> q;
            q.push({root, depth});
            pair<Node*,int> cur;
            while (!q.empty()) {
                //get next element 
                cur = q.front();
                q.pop();

                //check for children
                if(cur.first->left) {
                    q.push({cur.first->left, cur.second + 1});
                    //cout << cur.first->left->val << endl;
                }
                if (cur.first->right) {
                    q.push({cur.first->right, cur.second + 1});
                    //cout << cur.first->right->val << endl;
                }

                //add next pointer
                if(q.front().second == cur.second) {
                    cur.first->next = q.front().first;
                }

            }     
        
            return root;
        }
};