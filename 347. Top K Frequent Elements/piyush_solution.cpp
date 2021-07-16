class Solution {
public:
    
    //O(nlogk) 
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(auto x:a)
            mp[x]++;
        
        vector<int> res;
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto x:mp)  //freq    element
        {
            pq.push({x.second,x.first});
            if(pq.size()>k)
                pq.pop();
        }
                
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
