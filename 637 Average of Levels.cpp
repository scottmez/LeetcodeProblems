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
        vector<double> averageOfLevels(TreeNode* root) {
            vector <double> result;
            vector<int> nodes; // this is used to keep track of the number of nodes at each level
            averageOfLevelsHelper(root, result, nodes, 0);
            // now we can divide each sum by the number of nodes at that level to get the average
            for (int i = 0; i < result.size(); i++) {
                if (nodes[i] != 0) {
                    result[i] /= nodes[i]; // calculate the average
                }
            }
            return result;
        }

        void averageOfLevelsHelper(TreeNode* root, vector<double>& result, vector<int>& nodes, int level) {
            if (root == nullptr) {
                return;
            }
            //if this is the first node of this level
            if (level == result.size()) {
                result.push_back(0.0); // initialize the sum
                nodes.push_back(0); // initialize the count of nodes at this level
            }
            // accumulate the sum and count of nodes at this level
            result[level] += root->val;
            nodes[level]++; // increment the count of nodes at this level

            averageOfLevelsHelper(root->left, result, nodes, level + 1);
            averageOfLevelsHelper(root->right, result, nodes, level + 1);
        }
    };