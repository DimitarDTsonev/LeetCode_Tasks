// Task : https://leetcode.com/problems/convert-bst-to-greater-tree/description/

#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int sum = 0;

void traverse(TreeNode* root) {
	if (root == nullptr) {
		return;
	}

	traverse(root->right);
	sum += root->val;
	root->val = sum;
	traverse(root->left);
}

TreeNode* convertBST(TreeNode* root) {
	traverse(root);
	return root;
}

void printTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}

	std::cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

void deleteTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	// Example 1:
	TreeNode* root = new TreeNode(4, new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
		new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));

	bstToGst(root);
	printTree(root);
	deleteTree(root);

	return 0;
}
