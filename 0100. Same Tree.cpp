// Task : https://leetcode.com/problems/same-tree/ 

#include<iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr) {
		return true;
	}
	if (p == nullptr || q == nullptr || p->val != q->val) {
		return false;
	}

	return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
}

int main() {
    // Test 1:
	TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

	std::cout << isSameTree(root1, root2) << std::endl;

    // Test 2:
	TreeNode* root3 = new TreeNode(1, new TreeNode(2), nullptr);
	TreeNode* root4 = new TreeNode(1, nullptr, new TreeNode(2));

	std::cout << isSameTree(root3, root4) << std::endl;

    // Test 3:
	TreeNode* root5 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
	TreeNode* root6 = new TreeNode(1, new TreeNode(1), new TreeNode(3));

	std::cout << isSameTree(root5, root6) << std::endl;
    
	return 0;
}
