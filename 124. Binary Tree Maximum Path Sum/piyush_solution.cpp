class Solution {
    
public:
    long  maxpath(TreeNode* root,long  &gmax)
    {
        if(root)
        {
            long  lmax = maxpath(root->left,gmax);
            long  rmax = maxpath(root->right,gmax);
            long  data = root->val;
            
            gmax = max({ gmax ,data+lmax ,data+rmax , data+lmax+rmax ,data });       //gmax stores globally maxpath that is possible
            return max({data , data+lmax , data+rmax});      //we return max possible path at lower level
        }
        return 0;
    }
    
    int maxPathSum(TreeNode* root) {
        long  gmax = LONG_MIN;
        maxpath(root,gmax);
        return gmax;
    }
};
