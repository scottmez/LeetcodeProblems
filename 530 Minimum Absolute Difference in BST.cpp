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
        int getMinimumDifference(TreeNode* root) {
            int min = INT_MAX; // initialize min to maximum possible integer
            int prev = -1; // this will store the previous node's value during in-order traversal
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
                
                // if prev is not -1, calculate the difference
                if (prev != -1) {
                    int diff = abs(current->val - prev);
                    if (diff < min) {
                        min = diff; // update min if we found a smaller difference
                    }
                }
                prev = current->val; // update prev to current node's value
                current = current->right; // move to the right subtree
            }
            return min; // return the minimum absolute difference found
        }
    };