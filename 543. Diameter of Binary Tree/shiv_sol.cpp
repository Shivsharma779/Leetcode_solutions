class Solution {
public:
    int ans;
    
    int hieght(TreeNode * root){
        if(!root) return 0;
        int l = hieght(root->left), r = hieght(root->right);
        if(l+r > ans) ans = l+r;
        
        return 1 + max( l , r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         ans = 0;
        hieght(root);
        return ans;
    }
};
