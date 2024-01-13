// Task : 

int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() { 
    
    return 0;
}
