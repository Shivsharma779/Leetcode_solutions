class Solution {
public:
    /*
    select-notSelect type DP
    if current root val is selected we add grandchild values to it (as 1 level         below is not allowed)
    if not selected we just select child values 
    */
    int rob(TreeNode* root) {
        if(root)
        {                        
            TreeNode  *l,*r,*ll,*rr,*lr,*rl;
            
            int childsum = rob(root->right) + rob(root->left);
            //(root->left)?root->left->val:0 + (root->right)?root->right->val:0;
            
            ll = (root->left)?root->left->left:0;
            lr = (root->left)?root->left->right:0;
            rr = (root->right)?root->right->right:0;
            rl = (root->right)?root->right->left:0;
            
            int grandchildsum = (ll?ll->val:0) + (lr?lr->val:0) + 
                                (rr?rr->val:0) + (rl?rl->val:0);
            
            root->val = max(root->val+grandchildsum , childsum);
        
            //cout<<root->val<<" "<<childsum<<" "<<grandchildsum<<"\n";
            return root->val;
        }
        return 0;
    }
};
