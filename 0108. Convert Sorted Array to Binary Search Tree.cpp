// Task : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

TreeNode* helper(const std::vector<int> nums, int begin, int end) {
	if (begin > end) {
		return nullptr;
	}

	int mid = begin + (end - begin) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = helper(nums, begin, mid - 1);
	root->right = helper(nums, mid + 1, end);

	return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
	return helper(nums, 0, nums.size() - 1);
}

void printBST(TreeNode* root) {
	if (!root) {
		return;
	}

	std::cout << root->val << " ";
	printBST(root->left);
	printBST(root->right);
}

int main() {
	// Example 1:
	std::vector<int> nums1 = { -10, -3, 0, 5, 9 };
	printBST(sortedArrayToBST(nums1));
	std::cout << '\n';

	// Example 2:
	std::vector<int> nums2 = { 1, 3 };
	printBST(sortedArrayToBST(nums2));
	std::cout << '\n';

	return 0;
}
