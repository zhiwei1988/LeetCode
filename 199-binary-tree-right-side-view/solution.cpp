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
        vector<int> res;
        queue<TreeNode*> tQueue;
        if (root == nullptr) {
            return res;
        }

        tQueue.push(root);
        while (!tQueue.empty()) {
            size_t size = tQueue.size();
            for (int i = 0; i < size; i++) {
                auto node = tQueue.front();
                tQueue.pop();
                if (i == 0) {
                    res.push_back(node->val);
                }

                if (node->right != nullptr) {
                    tQueue.push(node->right);
                }

                if (node->left != nullptr) {
                    tQueue.push(node->left);
                }
            }
        }

        return res;
    }
};
