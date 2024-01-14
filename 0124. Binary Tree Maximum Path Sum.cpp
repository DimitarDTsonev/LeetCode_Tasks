// Task: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

int getMaxAns(TreeNode* curr, int& max_ans) {
	if (!curr) return 0;
	int leftAns = getMaxAns(curr->left, max_ans);
	int rightAns = getMaxAns(curr->right, max_ans);
	max_ans = std::max(max_ans, std::max(curr->val, std::max(leftAns, std::max(rightAns, leftAns + rightAns)) + curr->val));
	return std::max(curr->val, std::max(leftAns, rightAns) + curr->val);
}

int maxPathSum(TreeNode* root) {
	int max_ans = INT_MIN;
	getMaxAns(root, max_ans);
	return max_ans;
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(1, new TreeNode(2),new TreeNode(3));
	std::cout << maxPathSum(root1) << std::endl;

	// Example 2:
	TreeNode* root2 = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15),
		new TreeNode(7)));
	std::cout << maxPathSum(root2) << std::endl;

    deleteBinaryTree(root1);
    root1 = nullptr;
    deleteBinaryTree(root2);
    root2 = nullptr;
    
	return 0;
}
