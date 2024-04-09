// Task : https://leetcode.com/problems/path-sum/description/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

#include <iostream>

bool hasPathSum(TreeNode* root, int targetSum) {
	if (!root) {
		return false;
	}
	if (!root->left && !root->right && root->val == targetSum) {
		return true;
	}

	return hasPathSum(root->left, targetSum - root->val) ||
		hasPathSum(root->right, targetSum - root->val);
}

int main() {
	// Example 1:
	TreeNode* t1 = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
		new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1))));
	std::cout << hasPathSum(t1, 22) << '\n';
	
	// Example 2:
	TreeNode* t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	std::cout << hasPathSum(t2, 5) << '\n';

	return 0;
}
