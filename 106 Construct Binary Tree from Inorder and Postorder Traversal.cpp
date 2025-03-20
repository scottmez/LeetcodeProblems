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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            //we know postorder[n-1] is the root
            //we know inorder[0] to inorder[rootIndex-1] is the left subtree
            //we know inorder[rootIndex+1] to inorder[n] is the right subtree
            return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);            
        }

        TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
            if (inStart > inEnd || postStart > postEnd) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int rootIndex = 0;
            for (int i = inStart; i <= inEnd; i++) {
                if (inorder[i] == postorder[postEnd]) {
                    rootIndex = i;
                    break;
                }
            }
            root->left = buildTreeHelper(inorder, postorder, inStart, rootIndex-1, postStart, postStart+rootIndex-inStart-1);
            root->right = buildTreeHelper(inorder, postorder, rootIndex+1, inEnd, postStart+rootIndex-inStart, postEnd-1);
            return root;
        }
};