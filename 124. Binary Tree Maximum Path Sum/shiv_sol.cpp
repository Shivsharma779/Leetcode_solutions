class Solution {
public:
    long BA = LONG_MIN;
    long helper(TreeNode * root){
        if(!root) return 0;
        
        long lst = (root->left)  ? helper(root->left)  : 0;
        long rst = (root->right) ? helper(root->right) : 0;
        lst = (lst>0)?lst:0;
        rst = (rst>0)?rst:0;
        
        BA = max(BA,root->val+lst+rst);
        // cout <<root->val<< " " << BA << endl;
        
        long path_max = max(lst,rst);
        BA = max(BA,root->val+path_max);
        // cout <<root->val<< " " <<  BA << endl;
        
        return (root->val + path_max);
    }
    
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return BA;
        
    }
};
