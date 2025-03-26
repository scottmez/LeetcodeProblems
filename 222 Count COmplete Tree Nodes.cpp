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
        int countNodes(TreeNode* root) {
            if (!root) {
                return 0;
            }
            if (!root->left) {
                return 1;
            }

            int height = 1;
            int maxheight = 0;
            int leaves = 0;

            stack<pair<TreeNode*, int>> s;
            s.push({root,height});
            pair<TreeNode*, int> cur;
            
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                root = cur.first;
                height = cur.second;
                if (!root->left && !root->right) {
                    if (height >= maxheight) {
                        maxheight = height;
                        leaves += 1;
                        continue;
                    }
                    else {
                        //if height is less, then we have found all leaf nodes
                        break;
                    }
                }
                if (!root->right) {
                    //we have found all leaf nodes
                    s.push({root->left, height + 1});
                    continue;
                }
                s.push({root->right, height + 1});
                s.push({root->left, height + 1});
            }
            cout << "maxheight:" << maxheight << endl;
            return int(pow(2,maxheight-1) - 1) + leaves;
        }
    };