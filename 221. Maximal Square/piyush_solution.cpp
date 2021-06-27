class Solution {
public:
        
    int maximalSquare(vector<vector<char>>& mat) 
    {
        int n=mat.size() , m=mat[0].size(),res=0;
        int dp[n][m];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=(mat[i][j]=='1') ? 1 : 0;
                else if(mat[i][j]=='1')
                    dp[i][j]=1 + min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
                else
                    dp[i][j]=0;
                
                res=max(res,dp[i][j]);
            }
        }
        
        return res*res;
    }
};
