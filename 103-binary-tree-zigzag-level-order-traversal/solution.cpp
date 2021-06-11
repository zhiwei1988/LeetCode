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
        int level = 1;
        stack<TreeNode*> tStack;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        tStack.push(root);
        while (!tStack.empty()) {
            int size = tStack.size();
            queue<TreeNode*> tQueue;
            while (!tStack.empty()) {
                tQueue.push(tStack.top());
                tStack.pop();
            }
            vector<int> levelRes;
            for (int i = 0; i < size; i++) {
                TreeNode *node = tQueue.front();
                levelRes.push_back(node->val);
                tQueue.pop();
                if (level % 2 != 0) {
                    if (node->left != nullptr) {
                        tStack.push(node->left);
                    }

                    if (node->right != nullptr) {
                        tStack.push(node->right);
                    }
                } else {
                    if (node->right != nullptr) {
                        tStack.push(node->right);
                    }

                    if (node->left != nullptr) {
                        tStack.push(node->left);
                    }
                }
            }

            level++;
            res.push_back(levelRes);
        }

        return res;
    }
};
