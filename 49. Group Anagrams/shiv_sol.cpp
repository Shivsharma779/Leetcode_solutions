class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<int>,vector<string>> m;
        vector<vector<string>> ans;
        for(auto s : strs){
            vector<int> a(26,0);
            for(auto c : s){
                a[c-'a']++;
            }
            m[a].push_back(s);
                
            
        } 
        for(auto e: m){
            ans.push_back(e.second);
        }
        return ans; 
    }
};
