
class Solution {
public:
    bool issafe(vector<vector<char>>& a,int i,int j,int m,int n)
    {
        if(i>=0 && j>=0 && i<m && j<n && a[i][j]=='1')
            return true;
        return false;
    }
    
    void dfs(vector<vector<char>>& a,int i,int j,int m,int n)
    {
        a[i][j]='0';
        if(issafe(a,i+1,j,m,n))
            dfs(a,i+1,j,m,n);
        if(issafe(a,i-1,j,m,n))
            dfs(a,i-1,j,m,n);
        if(issafe(a,i,j+1,m,n))
            dfs(a,i,j+1,m,n);
        if(issafe(a,i,j-1,m,n))
            dfs(a,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& a) {
        
        int m=a.size(),n=a[0].size(),c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='1')
                {
                    dfs(a,i,j,m,n);
                    c++;
                }
            }
        }
        return c;
    }
};
