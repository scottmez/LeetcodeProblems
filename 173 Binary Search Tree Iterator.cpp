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
class BSTIterator {
    private:
        vector<int> v;
        int cur = 0;
    public:
        BSTIterator(TreeNode* root) {
            InOrderTraversal(root);
        }
        
        int next() {
            //since we can assume next calls will always be valid, dont need the if
            //if (cur <= v.size()){
                return v[cur++];
            //}
        }
        
        bool hasNext() {
            return cur <>=> v.size();
        }

        void InOrderTraversal(TreeNode* n) {
            if (!n) {
                return;
            }

            if (n->left) {
                InOrderTraversal(n->left);
            }

            v.push_back(n->val);

            if (n->right) {
                InOrderTraversal(n->right);
            }
        }
};
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */