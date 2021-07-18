class Solution {
public:
    void util(vector<int>& a, int i, vector<int> &tempv, vector<vector<int>> &res)
    {
        if(i==a.size())
            res.push_back(tempv);
        else
        {
            util(a,i+1,tempv,res);      //not select
            tempv.push_back(a[i]);
            util(a,i+1,tempv,res);      //select
            tempv.pop_back();            
        }
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> res;
        vector<int> tempv;
        util(a,0,tempv,res);
        return res;
    }
};
