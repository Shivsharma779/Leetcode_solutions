class Solution {
public:
    int numDecodings(string &s) {
        int n = s.size();
        vector<int> dp(3,0);
        dp[2] = dp[1] = 1;
        for(int i = n-1 ; i > -1 ; i--){
            if(s[i] != '0'){
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7') ) ) 
                    dp[0] += dp[2];
                dp[0] += dp[1];
            }

               
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = 0;
            
        }
        
        return dp[1];
    }
};
