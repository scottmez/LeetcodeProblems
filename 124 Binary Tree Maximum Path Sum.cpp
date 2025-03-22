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
    private:
        int maxSum = INT_MIN;
    public:
        int maxPathSum(TreeNode* root) {
            //basic idea is to find the maximum value of each node and its children
            //but we only return the node val + the bigger of the two children
            maxNodeSum(root);
            return maxSum;
        }

        int maxNodeSum(TreeNode* t) {
            if (!t) {
                return 0;
            }

            int left = max(0, maxNodeSum(t->left));
            int right = max(0, maxNodeSum(t->right));

            maxSum = max(maxSum, left + right + t->val);
            return max(0, max(left, right) + t->val);
        } 
};