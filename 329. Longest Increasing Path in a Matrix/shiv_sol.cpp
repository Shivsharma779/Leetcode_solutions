class Solution {
public:
    
    int dfs(int i , int j, vector<vector<int>> &M , vector<vector<int>> &dp){
        
        int n = M.size() , m = M[0].size();
        
        
        
        if(dp[i][j] != 0) return dp[i][j];
        int temp = M[i][j];
        M[i][j] = -1;
        int l,r , u , d;
        int ans = 1;
        
        l = (j>0 && M[i][j-1] > temp)  ? dfs(i,j-1,M,dp) : 0;
        r = (j<m-1 && M[i][j+1] > temp)? dfs(i,j+1,M,dp) : 0;
        u = (i>0 && M[i-1][j] > temp)  ? dfs(i-1,j,M,dp) : 0;
        d = (i<n-1 && M[i+1][j] > temp)? dfs(i+1,j,M,dp) : 0;
        M[i][j] = temp;
        
        int path = max(l,max(r,max(u,d)));
        return dp[i][j] = ans+path;
    }
    int longestIncreasingPath(vector<vector<int>>& M) {
        int n = M.size() , m = M[0].size();
        int ans = INT_MIN;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                ans = max(ans,dfs(i,j,M,dp));
                
            }
        }
        return ans;

    }
};
