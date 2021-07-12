class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(i==0 && j==0)
                    continue;
                else if(i==0)
                    a[i][j]+=a[i][j-1];
                else if(j==0)
                    a[i][j]+=a[i-1][j];
                else 
                    a[i][j]+=min(a[i-1][j],a[i][j-1]);
        
        return a[m-1][n-1];
    }
};
