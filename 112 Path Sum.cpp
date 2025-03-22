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
        bool hasPathSum(TreeNode* root, int targetSum) {
            //need to find the sums of all paths
            //how many paths? num paths == num leaf nodes
            if (!root) {
                return false;
            }

            stack<TreeNode*> s;
            s.push(root);
            while (!s.empty()) {
                TreeNode* cur = s.top();
                s.pop();
                if (cur->right) {
                    s.push(cur->right);
                    cur->right->val += cur->val;
                }
                if (cur->left) {
                    s.push(cur->left); 
                    cur->left->val += cur->val;
                }
                
                //check target sum if leaf node
                if (!cur->left && !cur->right && cur->val == targetSum) {
                    return true;
                }
            }
            return false;
        }
};