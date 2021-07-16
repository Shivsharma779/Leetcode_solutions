class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int n=a.size();
        for(int i=0;i<n-1;i++)          //transpose
            for(int j=i+1;j<n;j++)
                swap(a[i][j],a[j][i]);
            
        for(int i=0;i<n;i++)            //rotate horizontally 180
            for(int j=0;j<n/2;j++)
                swap(a[i][j],a[i][n-j-1]);
    }
};
