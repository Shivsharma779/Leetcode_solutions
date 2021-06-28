class Solution {
public:
    
    bool wordBreak(string s, vector<string>& W) {
        int n = s.size();
        unordered_set<string> d;
        for(string w : W) d.insert(w);
        vector<bool> dp(n+1,false);
        dp[n] = true;
        for(int i = n-1 ; i > -1 ; i--){
            for(int j =i; j < n; j++){
                if(dp[j+1] && d.find(s.substr(i,j-i+1)) != d.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
