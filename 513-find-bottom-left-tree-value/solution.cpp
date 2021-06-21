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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            size_t nodeNum = nodeQueue.size();
            for (int32_t i = 0; i < nodeNum; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (i == 0) {
                    res = node->val;
                }

                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                }

                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                }
            }
        }
        return res;
    }
};
