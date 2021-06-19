int jump(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n,INT_MAX-1);
        dp[n-1] = 0;
        for(int i = n-2; i > -1 ; i--){
            
            for(int j = 1; j<=A[i]; j++){
                if (i+j < n) 
                    dp[i] = min(dp[i],1+dp[i+j]);
            }
            cout << dp[i] << "\n";
        }
        return dp[0];
    }
