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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            //we know preorder[0] is the root
            //we know inorder[0] to inorder[rootIndex-1] is the left subtree
            //we know inorder[rootIndex+1] to inorder[n] is the right subtree
            return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);     
        }

        TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
            if (preStart > preEnd || inStart > inEnd) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[preStart]);
            int rootIndex = 0;
            for (int i = inStart; i <= inEnd; i++) {
                if (inorder[i] == preorder[preStart]) {
                    rootIndex = i;
                    break;
                }
            }
            root->left = buildTreeHelper(preorder, inorder, preStart+1, preStart+rootIndex-inStart, inStart, rootIndex-1);
            root->right = buildTreeHelper(preorder, inorder, preStart+rootIndex-inStart+1, preEnd, rootIndex+1, inEnd);
            return root;
        }
    };