class Solution {
public:
    int ans;
    int dfs(vector<vector<char>> &M , int i , int j, vector<vector<int>> &dp){
        
        int n = M.size() , m = M[0].size();
        
        if( i == n || j == m ) return 0;
        
        if(M[i][j] == '0') return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];
        int r = sqrt(dfs(M,i,j+1,dp)) , d = sqrt(dfs(M,i+1,j,dp)) , g = sqrt(dfs(M,i+1,j+1,dp));
        if(min(r,min(d,g)) == 0) return dp[i][j] = 1;
        // if(i == 0&& j == 0) cout << r << " " << d << " " << g << endl;
        dp[i][j] = pow(2, min(r,min(d,g)) + 1);
        cout << i << " " << j << " " << dp[i][j] << " " <<  min(r,min(d,g))  << endl;

        return dp[i][j];
        
    }
    int maximalSquare(vector<vector<char>>& M) {
        ans = 0;
        
        int n = M.size() , m = M[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i = n-1; i > -1 ; i--){
            for(int j = m-1 ; j > -1 ; j--){
                if(M[i][j] == '1'){
                    if(i+1 < n && j+1 < m){
                        int r = dp[i][j+1];
                        int d = dp[i+1][j];
                        int g = dp[i+1][j+1];
                       
                        dp[i][j] = min( r , min( d , g )) +1 ;
                    }
                    else dp[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                // cout << dp[i][j] << " ";
                ans = max(ans,dp[i][j]);
            }        
            // cout << endl;
        }

        return pow(ans,2);
        
    }
};
