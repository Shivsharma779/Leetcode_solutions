class Solution {
public:
    bool sym(TreeNode * l , TreeNode *  r){
        if((!l && r) || (l && !r)) return false;
        if(!l && !r) return true;
        
        if(l->val == r->val){
            return (sym(l->left, r->right) && sym(l->right, r->left));
        }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return sym(root->left, root->right);
    }
};
