// Task : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

#include<iostream>

struct TreeNode {
private:
	void deleteTree(TreeNode* root) {
		if (!root) {
			return;
		}

		deleteTree(root->left);
		deleteTree(root->right);

		delete[] root;
	}
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
	~TreeNode() { deleteTree(this); }
};


bool isLeaf(TreeNode* root) {
	return (!root->left && !root->right);
}

int sumNumbers(TreeNode* root, int cur) {
	if (!root) {
		return 0;
	}

	cur = cur * 10 + root->val;

	if (isLeaf(root)) {
		return cur;
	}

	return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);
}

int sumNumbers(TreeNode* root) {
	return  sumNumbers(root, 0);
}

int main() {
	// Example 1:
	TreeNode* t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	std::cout << sumNumbers(t1) << '\n';

	// Example 2:
	TreeNode* t2 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
	std::cout << sumNumbers(t2) << '\n';

	return 0;
}
