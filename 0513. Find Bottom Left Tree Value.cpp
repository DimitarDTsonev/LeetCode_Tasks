// Task: https://leetcode.com/problems/find-bottom-left-tree-value/description/

#include<iostream>
#include<queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int findBottomLeftValue(TreeNode* root) {
	if (!root) {
		return 0;
	}

	std::queue<TreeNode*> q;
	q.push(root);
	int front = INT_MIN;

	while (!q.empty()) {
		int levelSize = q.size();
		for (int i = 0; i < levelSize; ++i) {
			TreeNode* node = q.front();
			q.pop();
			front = node->val;

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
	}

	return front;
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
	TreeNode* t1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
	std::cout << findBottomLeftValue(t1) << "\n";

	// Example 2:
	TreeNode* t2 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr),
		new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)));
	std::cout << findBottomLeftValue(t2) << "\n";

	deleteTree(t1);
    	t1 = nullptr;
	deleteTree(t2);
    	t2 = nullptr;
    
	return 0;
}
