// Task : https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

#include<iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right){}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }
        
    unsigned sum = 0;

    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    return sum;
}

void deleteTree(TreeNode* root){
    if(!root){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete[] root;
}

int main() {
    // Example 1:
    TreeNode* t1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    std::cout << sumOfLeftLeaves(t1) << '\n';
    
    // Example 2:
    TreeNode* t2 = new TreeNode(1);
    std::cout << sumOfLeftLeaves(t2) << '\n';

    deleteTree(t1);
    deleteTree(t2);
    
    return 0;
}
