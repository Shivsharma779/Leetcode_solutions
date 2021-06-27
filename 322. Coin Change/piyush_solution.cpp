
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,INT_MAX-1);
        //sort(coins.begin(),coins.end());
        dp[0]=0;
        
        for(int i=0;i<coins.size();i++)
            for(int j=1;j<=amount;j++)
                if(coins[i]<=j)
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
        
        return   (dp[amount]>amount)?-1:dp[amount];
        
    }
};
