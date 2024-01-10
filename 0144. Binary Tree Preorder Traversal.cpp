// Task: 144. Binary Tree Preorder Traversal, https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include<iostream>
#include<vector>
#include<stack>

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

void printVector(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

// Iterative way using std::stack and dfs:
std::vector<int> preorderTraversal(TreeNode* root) {
	if (!root) {
		return std::vector<int>(0);
	}
	std::vector<int> vec;
	std::stack<TreeNode*> stack;

	stack.push(root);

	while (!stack.empty()) {
		TreeNode* curr = stack.top();
		vec.push_back(curr->val);
		
		stack.pop();
		
		if (curr->right) {
			stack.push(curr->right);
		}
		
		if (curr->left) {
			stack.push(curr->left);
		}
		
	}

	return vec;
}

// Classic way using recursion and dfs: 
std::vector<int> vec;

std::vector<int> preorderTraversal(TreeNode* root) {
	if (!root) {
		return std::vector<int>(0);
	}
	
	vec.push_back(root->val);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

	return vec;
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
	std::vector<int> vec1 = preorderTraversal(root1);
	printVector(vec1);

	//Example 2:
	TreeNode* root2 = nullptr;
	std::vector<int> vec2 = preorderTraversal(root2);
	printVector(vec2);

	// Example 1:
	TreeNode* root3 = new TreeNode(1);
	std::vector<int> vec3 = preorderTraversal(root3);
	printVector(vec3);

    deleteBinaryTree(root1);
    root1 = nullptr;
    deleteBinaryTree(root2);
    root2 = nullptr;
    deleteBinaryTree(root3);
    root3 = nullptr;    
	return 0;
}
