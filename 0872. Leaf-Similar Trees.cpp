// Task: https://leetcode.com/problems/leaf-similar-trees/

#include<iostream>
#include<vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void getLeafs(TreeNode* root, std::vector<int>& leafs) {
	TreeNode* tmp = root;
	if (!root) {
		return;
	}

	if (!tmp->left && !tmp->right && tmp) {
		leafs.push_back(tmp->val);
	}

	getLeafs(tmp->left, leafs);
	getLeafs(tmp->right, leafs);

	return;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	if (!root1 && !root2) {
		return true;
	}
	if (root1 && !root2) {
		return false;
	}
	if (!root1 && root2) {
		return false;
	}
	
	std::vector<int> leafs1, leafs2;

	getLeafs(root1, leafs1);
	getLeafs(root2, leafs2);

	for (size_t i = 0; i < std::max(leafs1.size(), leafs2.size()); i++)	{
		if (leafs1[i] != leafs2[i]) {
			return false;
		}
	}

	return true;
}

void deleteTree(TreeNode* tree) {
	if (!tree) {
		return;
	}

	deleteTree(tree->left);
	deleteTree(tree->right);
	
	delete tree;
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(3,
		new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
		new TreeNode(1, new TreeNode(9), new TreeNode(8)));

	TreeNode* root2 = new TreeNode(3,
		new TreeNode(5, new TreeNode(6), new TreeNode(7)),
		new TreeNode(1, new TreeNode(4), new TreeNode(2, new TreeNode(9), new TreeNode(8))));

	std::cout << leafSimilar(root1, root2) << std::endl;
	
	// Example 2:
	TreeNode* root3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	TreeNode* root4 = new TreeNode(1, new TreeNode(3), new TreeNode(2));
	std::cout << leafSimilar(root3, root4) << std::endl;

	// Clearing the memory of the whole trees!
	deleteTree(root1);
	deleteTree(root2);
	root1 = nullptr;
	root2 = nullptr;

	deleteTree(root3);
	deleteTree(root4);
	root3 = nullptr;
	root4 = nullptr;

	return 0;
}
