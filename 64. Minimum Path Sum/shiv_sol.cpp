class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> dp(m,0);
        for(int i = n-1 ; i > -1 ; i-- ){
            for(int j = m-1 ; j > -1; j-- ){
                int min_path = INT_MAX;
                if (j+1 < m) min_path =   dp[1+j];
                if (i+1 < n) min_path = min(min_path,  + dp[j]);
                if(min_path ==  INT_MAX) min_path = 0;
                dp[j] = min_path + grid[i][j] ;
            }
            
        }
 
        return dp[0];
    }
};
