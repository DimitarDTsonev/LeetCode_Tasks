// Task : https://leetcode.com/problems/symmetric-tree/description/ 

#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }

    return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main() {
    // Example 1:
    TreeNode* t1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
        new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    std::cout << isSymmetric(t1) << '\n';

    // Example 2:
    TreeNode* t2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
        new TreeNode(2, nullptr, new TreeNode(3)));
    std::cout << isSymmetric(t2) << '\n';

    return 0;
}
