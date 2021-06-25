class Solution {
public:
    vector<int> dp;
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return dp[0] = 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    Solution(){
        dp = vector<int>(46,-1);
    }
    
};
