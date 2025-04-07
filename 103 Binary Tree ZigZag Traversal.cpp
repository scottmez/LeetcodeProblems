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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            if (root == nullptr) {
                return result; // return empty if the root is null
            }
            queue<TreeNode*> q;
            q.push(root);
            bool zigzag = true; // this will help us to toggle the order of insertion for each level
            while (!q.empty()) {
                int size = q.size();
                zigzag = !zigzag; // toggle the zigzag for each level
                vector<int> currentLevel;
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    currentLevel.push_back(node->val);
                    if (node->left) {
                        q.push(node->left); // push left child to the queue
                    }
                    if (node->right) {
                        q.push(node->right); // push right child to the queue
                    }
                }
                if (zigzag) {
                    // reverse the current level if zigzag is false
                    reverse(currentLevel.begin(), currentLevel.end());
                }
                result.push_back(currentLevel);
            }
            return result;  
        }
    };