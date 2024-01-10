// Task: 617. Merge Two Binary Trees: https://leetcode.com/problems/merge-two-binary-trees/description/

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

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr && root2 == nullptr) {
		return nullptr;
	}

	int value1 = (root1 == nullptr) ? 0 : root1->val;
	int value2 = (root2 == nullptr) ? 0 : root2->val;

	TreeNode* newNode = new TreeNode(value1 + value2);

	if (root1 != nullptr || root2 != nullptr) {
		newNode->left = mergeTrees((root1 == nullptr) ? nullptr : root1->left,
			(root2 == nullptr) ? nullptr : root2->left);

		newNode->right = mergeTrees((root1 == nullptr) ? nullptr : root1->right,
			(root2 == nullptr) ? nullptr : root2->right);
	}

	return newNode;
}

void printTree(TreeNode* root) {
	if (!root) {
		return;
	}

	printTree(root->left);
	std::cout << root->val << " ";
	printTree(root->right);
}

int main() {
	TreeNode* root1 = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
	TreeNode* root2 = new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4)), 
		new TreeNode(3, nullptr, new TreeNode(7)));

	TreeNode* sum = mergeTrees(root1, root2);
	printTree(sum);

	deleteBinaryTree(root1);
	root1 = nullptr;
	deleteBinaryTree(root2);
	root2 = nullptr;
    deleteBinaryTree(sum);
    sum = nullptr;
    
	return 0;
}
