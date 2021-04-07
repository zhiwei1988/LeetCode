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
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }

    void traverse(TreeNode* node, int k) {
        if (node == nullptr) return;
        traverse(node->left, k);
        count++;
        if (count == k) {
            res = node->val;
            return;
        }
        traverse(node->right, k);
    }

private:
    int res;
    int count = 0;
};
