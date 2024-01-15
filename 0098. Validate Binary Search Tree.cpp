// Task: https://leetcode.com/problems/validate-binary-search-tree/description/

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void deleteTree(TreeNode* tree) {
	if (!tree) {
		return;
	}

	deleteTree(tree->left);
	deleteTree(tree->right);
	
	delete tree;
}

bool validate(TreeNode* root, long min, long max) {
	if (!root) {
		return true;
	}

	if (root->val <= min || root->val >= max) {
		return false;
	}

	return validate(root->left, min, root->val) &&
		validate(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
	if (!root) {
		return true;
	}
	return validate(root, LONG_MIN, LONG_MAX);
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	std::cout << isValidBST(root1) << std::endl;
	
	// Example 2:
	TreeNode* root2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), 
		new TreeNode(6)));
	std::cout << isValidBST(root2) << std::endl;

	return 0;
}
