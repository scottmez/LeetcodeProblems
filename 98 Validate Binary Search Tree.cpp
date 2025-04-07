/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            TreeNode* prev = nullptr; // this will store the previous node during in-order traversal
            stack<TreeNode*> s;
            TreeNode* current = root;
            while (current != nullptr || !s.empty()) {
                // reach the leftmost node of the current node
                while (current != nullptr) {
                    s.push(current);
                    current = current->left;
                }
                // current must be null at this point, so we process the top of the stack
                current = s.top();
                s.pop();
                
                // if prev is not nullptr, compare to current node's value
                if (prev != nullptr) { 
                    if (prev->val >= current->val) {
                        return false; // if the previous value is greater than or equal to the current node's value, it is not a valid BST
                    }
                }
                prev = current; // update prev to current node's value
                current = current->right; // move to the right subtree
            }
            return true; // if we successfully completed the in-order traversal without finding any violations, it is a valid BST
        }
    };