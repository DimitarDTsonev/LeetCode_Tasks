// Task: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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

// This function do the job if you test it to your compiler but notice that if you want to submit the task to  
// LeetCode you must add a variable of type TreeNode* to hold the answear outside the function and than return 
// the answear to the end of the function!
TreeNode* searchBST(TreeNode* root, int val) {
	if (!root) {
		return nullptr;
	}

	if (root->val == val) {
		return root;
	}
	else if (root->val < val) {
		searchBST(root->right, val);
	}
	else if (root->val > val) {
		searchBST(root->left, val);
	}
}

int main() {

	TreeNode* root1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

	// In the task we need to return the whole subtree but for facilitation I chose to print 1 or 0!
	// Example 1:
	if (searchBST(root1, 2)) {
		std::cout << 1 << std::endl;
	}
	else {
		std::cout << 0 << std::endl;
	}

	// Examplse 2:
	if (searchBST(root1, 5)) {
		std::cout << 1 << std::endl;
	}
	else {
		std::cout << 0 << std::endl;
	}

	// Clearing the memory!
	deleteBinaryTree(root1);
	root1 = nullptr;

	return 0;
}
