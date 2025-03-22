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
        int sumNumbers(TreeNode* root) {
            if (!root) {
                return 0;
            }

            int totalSum = 0;
            stack<TreeNode*> s;
            s.push(root);
            while (!s.empty()) {
                TreeNode* cur = s.top();
                s.pop();
                if (cur->right) {
                    s.push(cur->right);
                    cur->right->val += cur->val * 10;
                }
                if (cur->left) {
                    s.push(cur->left); 
                    cur->left->val += cur->val * 10;
                }

                //check if leaf node
                if (!cur->left && !cur->right) {
                    totalSum += cur->val;
                }
            }
            return totalSum;
        }
    };