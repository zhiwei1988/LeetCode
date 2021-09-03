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
    int maxSumBST(TreeNode* root) {
        GetSubtreeInfo(root);
        return res;
    }

private:
    struct SubTreeInfo {
        bool isBS = true;; // 是二叉搜索树
        int sum = 0; // 子树键值之和
        int min = INT_MAX; // 子树中的最小值
        int max = INT_MIN; // 子数中的最大值
    };

    SubTreeInfo GetSubtreeInfo(TreeNode* root)
    {
        SubTreeInfo info {};

        if (root == nullptr) {
            return info;
        }

        auto lInfo = GetSubtreeInfo(root->left);
        auto rInfo = GetSubtreeInfo(root->right);

        if (!lInfo.isBS || !rInfo.isBS || root->val <= lInfo.max || root->val >= rInfo.min) {
            info.isBS = false;
            return info;
        }

        if (root->left) {
            // 若存在左子树，则当前子树的最小值为，左子树的最小值
            info.min = lInfo.min;
        } else {
            info.min = root->val;
        }

        if (root->right) {
            // 若存在右子树，则当前子树的最大值为，右子树的最小值
            info.max = rInfo.max;
        } else {
            info.max = root->val;
        }

        info.sum = root->val + lInfo.sum + rInfo.sum;
        res = max(res, info.sum);
        return info;
    }

    int res = 0;
};
