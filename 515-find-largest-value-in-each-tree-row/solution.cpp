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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        int maxVal = INT_MIN;
        queue<TreeNode*> nodeQueue;
        if (root == nullptr) {
            return res;
        }

        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            size_t qSize = nodeQueue.size();
            maxVal = INT_MIN;
            for (int i = 0; i < qSize; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                maxVal = max(maxVal, node->val);

                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                }

                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                }
            }

            res.push_back(maxVal);
        }

        return res;
    }
};
