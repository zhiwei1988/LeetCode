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
    bool isValidBST(TreeNode* root) {
        return validateBstHelper(root, LONG_MIN, LONG_MAX);
    }
private:
    // 此处 min 和 max 类型取 long long 因为 val 值可能等于 INT_MIN 或 INT_MAX
    bool validateBstHelper(TreeNode *node, long long min, long long max) {
        // 如果节点为空
        if (node == nullptr) {
            return true;
        }
        
        // 当前节点的值不符合 BST 的定义
        if (node->val <= min || node->val >= max) {
            return false;
        }
        
        // 判断左子节点是否满足 BST 的定义, 对于左子节点，父节点的最小值，也是它的最小值
        bool leftIsValid = validateBstHelper(node->left, min, node->val);
        
        // 判断右子节点是否满足 BST 的定义, 对于右子节点，父节点的最大值，也是它的最大值
        bool rightIsValid = validateBstHelper(node->right, node->val, max);
        
        return leftIsValid && rightIsValid;
    }
};
