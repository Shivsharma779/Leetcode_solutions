class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        int n=a.size();
        if(n==0)
            return res;
        
        sort(a.begin(),a.end(),compare);    //sort on start time,
                                            //end time handled below
        
        int st=a[0][0],ed=a[0][1];
        for(int i=1;i<n;i++)
        {
            if(a[i][0]<=ed)
                ed=max(ed,a[i][1]);     //next interval completely inside 
                                        //current interval e.g. [[1,4][2,3]]
            else    
            {
                res.push_back({st,ed});
                st=a[i][0];
                ed=a[i][1];
            }
        }
        res.push_back({st,ed});
        return res;
        
    }
};
