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
        int kthSmallest(TreeNode* root, int k) {
            int count = 0; // this will keep track of the number of nodes processed
            stack<TreeNode*> s; // stack to perform in-order traversal
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
                
                // increment the count of processed nodes
                count++;
                
                // if count is equal to k, return the value of the current node
                if (count == k) {
                    return current->val;
                }
                
                // move to the right subtree
                current = current->right;
            }
            return -1; // in case k is larger than the number of nodes in the BST, though this should not happen as per problem constraints
        }
    };