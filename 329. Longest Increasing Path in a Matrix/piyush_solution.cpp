class Solution {
public:
    //https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/78308/15ms-Concise-Java-Solution
    vector<pair<int,int>> dirs={{1,0} , {0,1} , {0,-1} , {-1,0}};
    
    bool issafe(vector<vector<int>>& matrix ,int i,int j, int &m, int &n , int &prev)
    {
        if(i>=0 && j>=0 && i<m && j<n && matrix[i][j] > prev)
            return true;
        return false;
    }
    
    int dfs(vector<vector<int>>& matrix , int dp[][200] , int i,int j, int &m, int &n)
    {
        if(dp[i][j] > 0)     //this path has been seen
            return   dp[i][j];
        
        int cmax = 1;
        
        for(auto dir:dirs)
            if(issafe(matrix , i+dir.first , j+dir.second , m , n , matrix[i][j]))
                cmax = max(cmax , 1 + dfs(matrix,dp,i+dir.first , j+dir.second ,m,n));
        
        dp[i][j] = cmax;
        //cout<<i<<" "<<" "<<dp[i][j]<<"\n";
        return cmax;
    }
    
    void printarr(vector<vector<int>>& matrix,int &m,int &n){
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
                
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)    return 0;
        int m=matrix.size() , n=matrix[0].size(),maxl=0;
        int dp[200][200]={};       
        //dp array stores longest inncreasing path at each point. if we reach a point where dp[i][j] !=0 that means it has been visited (longest inc path found) and we can directly use the value at that point without calling dfs. saves time.
            
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                maxl = max(maxl , dfs(matrix,dp,i,j,m,n));
        
        //printarr(dp,m,n);
        return maxl;
    }
};
