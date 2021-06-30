class Solution {
    
public:
    
    bool part(vector<int> &no, int target, int sA, int i, vector<vector<int>> &dp ){
        int n = no.size();
        
        if(sA > target || i > n-1) return  false;
        if(sA == target) return dp[i][sA] = true;
        if(dp[i][sA] != -1) return dp[i][sA];
        
        return dp[i][sA] = (part(no,target,sA+no[i],i+1,dp) || part(no,target,sA,i+1,dp));
        
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i =0 ; i < n ; i++) sum+= nums[i];
        
        if(sum%2 == 0){
            vector<vector<int>> dp(n+1,vector<int>(sum/2 + 1,-1));
            
            bool ans = part(nums,sum/2,0,0,dp);
            return ans;
        }
        else
            return false;
    }
};
