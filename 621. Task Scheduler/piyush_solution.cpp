class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x:tasks)
            mp[x]++;
        
        int res=0,maxfreq=0;
        for(auto x:mp)
            maxfreq = max(maxfreq,x.second);
        
        int gap = n;
        res = (maxfreq-1) * gap + maxfreq;
        
        for(auto x:mp)
            if(x.second == maxfreq)
                res++;
        
        return max(int(tasks.size()) , res-1);
        
    }
};

