class Solution {
public:
    //https://www.youtube.com/watch?v=uZzvivFkgtM
    void helper(TreeNode* root, int &target,int csum , unordered_map<int,int> &mp,int &res)
    {
        if(root)
        {
            csum += root->val;
            
            if(mp.find(csum - target)!=mp.end())
                res += mp[csum - target];
            
            mp[csum]++;
            helper(root->left,target,csum,mp,res);
            helper(root->right,target,csum,mp,res);
            mp[csum]--;
        }
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> mp;
        mp[0]=1;       //target path starts from root (nothing to subtract)
        int res=0;
        
        helper(root,sum,0,mp,res);
        
        return res;
    }
};
