class Solution {
public:
    
    void permut(int i,vector<int>& a,vector<vector<int>> &res)
    {
        if(i==a.size()-1)
            res.push_back(a);
        else
        {
            for(int j=i;j<a.size();j++)
            {
                swap(a[i],a[j]);
                permut(i+1,a,res);
                swap(a[i],a[j]);            
            }
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> res;
        permut(0,a,res);
        return res;
    }
};
