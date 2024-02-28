// Task: https://leetcode.com/problems/diameter-of-binary-tree/description/

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* node, int& diameter) {
	if (node == nullptr) {
		return 0;
	}

	int leftHeight = dfs(node->left, diameter);
	int rightHeight = dfs(node->right, diameter);

	diameter = std::max(diameter, leftHeight + rightHeight);

	return std::max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode* curr) {
    if (curr == nullptr) {
        return 0;
    }

    int diameter = 0;
    dfs(curr, diameter);
    return diameter;
}

void deleteTree(TreeNode* root) {
	if (!root) {
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	// Example 1: 
	TreeNode* t1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
	std::cout << diameterOfBinaryTree(t1) << "\n";

	// Example 2:
	TreeNode* t2 = new TreeNode(1, new TreeNode(2), nullptr);
	std::cout << diameterOfBinaryTree(t2) << "\n";

    deleteTree(t1);
    deleteTree(t2);
        
	return 0;
}
