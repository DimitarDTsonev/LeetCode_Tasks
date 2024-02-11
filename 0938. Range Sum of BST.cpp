// Task: https://leetcode.com/problems/range-sum-of-bst/description/

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
	if (!root || low > high) {
		return 0;
	}

	if (root->val < low) {
		return rangeSumBST(root->right, low, high);
	}
	if (high < root->val) {
		return rangeSumBST(root->left, low, high);
	}
	return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
	// Test:
	TreeNode* root = new TreeNode(10,
		new TreeNode(5,
			new TreeNode(3,
				new TreeNode(1),
				nullptr
			),
			new TreeNode(7,
				nullptr,
				new TreeNode(6)
			)
		),
		new TreeNode(15,
			new TreeNode(13),
			new TreeNode(18)
		)
	);


	std::cout << rangeSumBST(root, 6, 10);

	delete root;
	root = nullptr;
	
	return 0;
}
