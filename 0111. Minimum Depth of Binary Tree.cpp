// Task : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/ 

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

#include <iostream>

int minDepth(TreeNode* root) {
	std::ios_base::sync_with_stdio(false);
	if (!root) {
		return 0;
	}
	if (!root->left && !root->right) {
		return 1;
	}
	if (!root->left) {
		return minDepth(root->right) + 1;
	}
	if (!root->right) {
		return minDepth(root->left) + 1;
	}
	int lheight = minDepth(root->left);
	int rheight = minDepth(root->right);

	return std::min(lheight, rheight) + 1;
}

int main() {
	// Example 1:
	TreeNode* t1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	std::cout << minDepth(t1) << '\n';

	// Example 2:
	TreeNode* t2 = new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4, nullptr, 
		new TreeNode(5, nullptr, new TreeNode(6)))));
	std::cout << minDepth(t2) << '\n';

	return 0;
}
