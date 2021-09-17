class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> rmax(n,0),cmax(n,0);
        
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                cmax[j] = max(cmax[j], grid[i][j]);
                rmax[i] = max(rmax[i], grid[i][j]);
            }
        }
        
        int res=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res += min(cmax[j],rmax[i]) - grid[i][j]; 

        
        return res;
    }
};
