class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s:strs)
        {
            string temp=s;
            vector<int> freq(26,0);
            for(auto c:s)
                freq[c-'a']++;
            
            string key="";
            
            for(auto x:freq)
                key=key + to_string(x) + "#";
            
            mp[key].push_back(temp);
        }
        
        vector<vector<string>> res;
        
        for(auto x:mp)
            res.push_back(x.second);
        return res;
    }
};
