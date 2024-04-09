// Task : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    
    return 0;
}
