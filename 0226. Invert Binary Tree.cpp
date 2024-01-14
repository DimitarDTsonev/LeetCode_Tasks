 // Task: Task: 226 https://leetcode.com/problems/invert-binary-tree/description/

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void deleteBinaryTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}

	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	delete root;
}

void printTree(TreeNode* root) {
	if (!root) {
		return;
	}

	printTree(root->left);
	std::cout << root->val << " ";
	printTree(root->right);
}

TreeNode* invertTree(TreeNode* root) {
	if (!root) {
		return nullptr;
	}

	invertTree(root->left);
	invertTree(root->right);

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	return root;
}

int main() {
	// Examplse 1:
	TreeNode* root1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
		new TreeNode(7, new TreeNode(6), new TreeNode(9)));

	printTree(root1);
	std::cout << std::endl;
	root1 = invertTree(root1);
	printTree(root1);
	std::cout << std::endl;

	// Examplse 2:
	TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

	printTree(root2);
	std::cout << std::endl;
	root2 = invertTree(root2);
	printTree(root2);
	std::cout << std::endl;

	// Examplse 3:
	TreeNode* root3 = nullptr;

	printTree(root3);
	std::cout << std::endl;
	root3 = invertTree(root3);
	printTree(root3);
	std::cout << std::endl;

	return 0;
}
