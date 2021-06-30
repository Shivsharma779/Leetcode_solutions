class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) 
    {
        if(a.size())            //size>0
        {
            int i=a.size()-1,j=0,m=a.size(),n=a[0].size();
            while(i>=0 && j<n)
            {
                if(a[i][j]<target)
                    j++;
                else if(a[i][j]>target)
                    i--;
                else
                    return true;    //chance of found is less so 
                                    //we put is as last condition        
            }
        }
        return false;
    }
};
