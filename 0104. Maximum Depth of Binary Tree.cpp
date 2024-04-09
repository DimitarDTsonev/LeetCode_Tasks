// Task : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* _left, TreeNode* right) : val(x), left(_left), right(right){}
};

int maxDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() { 
    // Example 1:
    TreeNode* t1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7));
    std::cout << maxDepth(t1) << '\n';

    // Example 2:
    TreeNode* t2 = new TreeNode(1, nullptr, new TreeNode(2));
    std::cout << maxDepth(t2) << '\n';
    
    return 0;
}
