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

struct NodeInfo {
	int height; // 当前节点高度
	int diameter; // 以当前节点为root节点的树的直径
};

NodeInfo GetNodeInfo(TreeNode *tree) {
	NodeInfo nodeInfo {};
	if (tree == nullptr) {
		return nodeInfo;
	}
	
	NodeInfo leftSubTreeInfo = GetNodeInfo(tree->left);
	NodeInfo rightSubTreeInfo = GetNodeInfo(tree->right);
	
	int pathLenThroughRoot = leftSubTreeInfo.height + rightSubTreeInfo.height;
	int diameterSofar = max(leftSubTreeInfo.diameter, rightSubTreeInfo.diameter);
	nodeInfo.height = max(leftSubTreeInfo.height, rightSubTreeInfo.height) + 1;
	nodeInfo.diameter = max(pathLenThroughRoot, diameterSofar);
	
	return nodeInfo;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        NodeInfo nodeInfo = GetNodeInfo(root);
        return nodeInfo.diameter;
    }
};
