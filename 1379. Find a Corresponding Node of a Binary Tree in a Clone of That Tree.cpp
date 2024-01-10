// Task: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include<iostream>
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

TreeNode* tmp = nullptr;
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(!cloned){
            return tmp;
        }

    if(cloned->val == target->val){
        tmp = cloned;
        return tmp;
    }
    getTargetCopy(original, cloned->left, target);
    getTargetCopy(original, cloned->right, target);
    return tmp;
}

int main() {
	// Example 1:
	TreeNode* root1 = new TreeNode(7, new TreeNode(4), new TreeNode(3, new TreeNode(6), new TreeNode(19)));
	TreeNode* root2(root1);
	TreeNode* returned1 = getTargetCopy(root1, root2, root1->right);
	std::cout << returned1->val << std::endl;
	
	// Example 2:
	TreeNode* root3 = new TreeNode(7);
	TreeNode* root4(root3);
	TreeNode* returned2 = getTargetCopy(root3, root4, root3);
	std::cout << returned2->val << std::endl;

	// Example 3:
	TreeNode* root5 = new TreeNode(8, 
		nullptr, new TreeNode(6, 
			nullptr, new TreeNode(5, 
				nullptr, new TreeNode(4, 
					nullptr, new TreeNode(3, 
						nullptr, new TreeNode(2, 
							nullptr, new TreeNode(1)))))));
	TreeNode* root6(root5);
	TreeNode* returned3 = getTargetCopy(root5, root6, root5->right->right->right);
	std::cout << returned3->val << std::endl;

	return 0;
}
