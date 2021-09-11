class Solution {
public:
    //bucket sort
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(auto x:a)
            mp[x]++;
        
        
        int n=a.size();
        vector<int> buck[n+1];
        
        for(auto &x:mp)
            buck[x.second].push_back(x.first);
        
        vector<int> res;
        for(int i=n;i>=0 and res.size()<k;i--)
        {
            for(auto &x:buck[i])
            {
                res.push_back(x);
                if(res.size()==k)
                    break;
            }
        }
        
        return res;
    }
};
