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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tQueue;
        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        tQueue.push(root);
        while (!tQueue.empty()) {
            int size = tQueue.size();
            vector<int> levelRes;
            for (int i = 0; i < size; i++) {
                TreeNode *node = tQueue.front();
                tQueue.pop();
                levelRes.push_back(node->val);

                if (node->left != nullptr) {
                    tQueue.push(node->left);
                }

                if (node->right != nullptr) {
                    tQueue.push(node->right);
                }
            }
            res.push_back(levelRes);
        }

        return res;
    }
};
