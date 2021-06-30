class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int n = s.size();
        vector<int> ans;

        if( k > n) return ans;
        vector<int> pc(26,0);
        for(auto a: p) pc[a-'a']++;
        
        vector<int> kc(26,0);
        
        for(int i = 0 ; i < k && i<n ; i++) kc[s[i] - 'a'] ++;
        if(kc == pc) ans.push_back(0);
        
        for( int i = 1 ; i+k <= n ; i++){
            
            kc[s[i-1]-'a']--;
            kc[s[i+k-1] - 'a'] ++;
            
            if(kc == pc) ans.push_back(i);

        }
        return ans;
    }
};
