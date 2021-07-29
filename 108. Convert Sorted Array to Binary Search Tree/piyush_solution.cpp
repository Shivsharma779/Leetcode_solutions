class Solution {
public:
    TreeNode* buildtree(vector<int>& nums,int l,int r)
    {
        if(l<=r)
        {
            int m=(l+r)/2;
            TreeNode* cur = new TreeNode(nums[m]);
            cur->left = buildtree(nums, l , m-1);
            cur->right = buildtree(nums, m+1 , r);
            return cur;
        }
        return 0;
    }
        
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildtree(nums, 0 , nums.size()-1);
        
    }
};
