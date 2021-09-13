class Solution {
public:
    
    int helper(string &s, int k){
        unordered_map<char,int> m;
        for(auto a : s)   m[a]++;
        
        int n = s.size();
        if (n == 0) return 0;
        
        for(int i = 0; i < n ; i++){
            if( m[s[i]] < k ){
                int x = i+1;
                while(x < n && m[s[x]] < k) x++;
                string fr = s.substr(0,i);
                string sc = (x<n)?s.substr(x):"";
                
                int left = helper(fr,k);
                int right = helper(sc,k);
                
                
                return max(left,right);
                
            }
        }
        return n;
        
    }
    
    int longestSubstring(string s, int k) {
        
        // for(auto x : m)  cout << x.first << " " << x.second << endl;
        return helper(s,k);
        
    }
};
