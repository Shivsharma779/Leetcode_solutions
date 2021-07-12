class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        

        TreeNode * right = root->right, * right_holder = root;
        root->right = root->left;
        root->left = NULL;
        
        
        while(right_holder->right){
            right_holder = right_holder->right;
        }
        
        right_holder->right = right;
    }
};
