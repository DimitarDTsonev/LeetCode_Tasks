// Task: 94. Binary Tree Inorder Traversal, https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include<iostream>
#include<vector>
#include<stack>

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

void printVector(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> vec;

std::vector<int> inorderTraversal(TreeNode* root) {
	if (!root) {
		return std::vector<int>(0);
	}

	inorderTraversal(root->right);
	inorderTraversal(root->left);
	vec.push_back(root->val);

	return vec;
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
	std::vector<int> vec1 = inorderTraversal(root1);
	printVector(vec1);

	//Example 2:
	TreeNode* root2 = nullptr;
	std::vector<int> vec2 = inderTraversal(root2);
	printVector(vec2);

	// Example 1:
	TreeNode* root3 = new TreeNode(1);
	std::vector<int> vec3 = inorderTraversal(root3);
	printVector(vec3);

	deleteBinaryTree(root1);
	root1 = nullptr;
	deleteBinaryTree(root2);
	root2 = nullptr;
	deleteBinaryTree(root3);
	root3 = nullptr;

	return 0;
}
