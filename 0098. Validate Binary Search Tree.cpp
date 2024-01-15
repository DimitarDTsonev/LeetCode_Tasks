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
