/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        TreeNode* l = nullptr;
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            //check left
            //check right
            //evaluate 0/1
            if(!root) {
                return nullptr;
            }
            LCAhelper(root,p,q);
            return l;
        }
    
        int LCAhelper(TreeNode* root, TreeNode* p, TreeNode* q) {
            //1 = left
            //2 = right
            //3 = both
            if(!root) {
                return 0;
            }
            int left = LCAhelper(root->left, p, q);
            int right = LCAhelper(root->right, p, q);
            bool a = (root == p);
            bool b = (root == q);
            if (left == 3 || right == 3) {
                return 3;
            }
            if ((left == 1 || right == 1 || a) && (left == 2 || right == 2 || b)) {//if we have seen both p and q
                //then this should be the lowest common ancestor
                l = root;
                return 3;
            }
            return 1*(a) + 2*(b) + left + right; //1,2, or 3
        }
    };