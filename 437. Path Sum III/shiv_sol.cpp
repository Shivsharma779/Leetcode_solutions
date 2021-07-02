class Solution {
public:
    int helper(TreeNode * root, bool started, int t){
        if(!root) return 0;
        int ans = 0;
        if((t - root->val) == 0) return 1;
        int a = 0, b = 0,c,d;
        
        if(!started){
            a = helper(root->left, false , t);
            b = helper(root->right, false, t);    
        }
        c = helper(root->left, true,  t - (root->val));
        d = helper(root->right,true,  t - (root->val));
        ans += a + b + c + d;
       
        return ans;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        return helper(root,false,targetSum);
    }
};
