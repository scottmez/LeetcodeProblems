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
        vector<int> rightSideView(TreeNode* root) {
            //dfs prioritizing right side
            vector<int> result;
            rightSideViewHelper(root, result, 0);
            return result;
        }

        void rightSideViewHelper(TreeNode* root, vector<int>& result, int level) {
            if (root == nullptr) {
                return;
            }
            //if this is the first node of this level
            if (level == result.size()) {
                result.push_back(root->val);
            }
            //first go to the right side
            rightSideViewHelper(root->right, result, level+1);
            //then go to the left side
            rightSideViewHelper(root->left, result, level+1);
        }
    };