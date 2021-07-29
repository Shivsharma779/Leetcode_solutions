class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) 
    {
        vector<int> res;
        int m=a.size();
        if(m==0)
            return res;
        int n=a[0].size();
        
        int left=0,right=n-1,top=0,bottom=m-1,c=m*n,i,j;
        while(c)
        {
            //cout<<c<<" ";
            for(int i=left;i<=right && c;i++,c--)
                res.push_back(a[top][i]);
            top++;
            
            for(int i=top;i<=bottom && c;i++,c--)
                res.push_back(a[i][right]);
            right--;
            
            for(int i=right;i>=left && c;i--,c--)
                res.push_back(a[bottom][i]);
            bottom--;
            
            for(int i=bottom;i>=top && c;i--,c--)
                res.push_back(a[i][left]);
            left++;
        }
        
        return res;
        
        
    }
};
