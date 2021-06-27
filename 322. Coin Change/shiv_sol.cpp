class Solution {
public:
    
    
    int coinChange(vector<int>& coins, int a) {
        int n = coins.size();
        
        vector<int> dp(a+1,a+1);
        dp[0] = 0;
        
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 1 ; j <= a ; j++){
                if(coins[i] <= j ) dp[j] = min(dp[j], 1+dp[j-coins[i]]);
                
                
                
            }
            
        }
        
        int ans = dp[a];
        return (ans == a+1)?-1:ans;
    }
};
