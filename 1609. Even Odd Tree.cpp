// Task: https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

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

bool isEvenOddTree(TreeNode* root) {
	if (!root) {
		return true;
	}

	int level = 0;
	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();
		int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

		for (size_t i = 0; i < levelSize; i++) {
			TreeNode* node = q.front();
			q.pop();

			if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev)) ||
				(level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev))) {
				return false;
			}

			prev = node->val;

			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
		++level;
	}
	return true;
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
	TreeNode* t1 = new TreeNode(1, new TreeNode(10, new TreeNode(3, new TreeNode(12), new TreeNode(8)), nullptr),
		new TreeNode(4, new TreeNode(7, new TreeNode(6), nullptr), new TreeNode(9, nullptr, new TreeNode(2))));
	std::cout << isEvenOddTree(t1) << "\n";

	// Example 2:
	TreeNode* t2 = new TreeNode(5, new TreeNode(4, new TreeNode(3), new TreeNode(3)),
		new TreeNode(2, new TreeNode(7), nullptr));
	std::cout << isEvenOddTree(t2) << "\n";

	// Example 3:
	TreeNode* t3 = new TreeNode(5, new TreeNode(9, new TreeNode(3), new TreeNode(5)),
		new TreeNode(1, new TreeNode(7), nullptr));
	std::cout << isEvenOddTree(t3) << "\n";

	deleteTree(t1);
	t1 = nullptr;
	deleteTree(t2);
	t2 = nullptr;
	deleteTree(t3);
	t3 = nullptr;

	return 0;
}
