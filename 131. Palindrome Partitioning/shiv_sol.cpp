class Solution {
public:
    vector<vector<string>> ans;

    bool palin(string &s , int i , int j ,vector<vector<bool>> &dp){
        if(j-i+1 <=2) return dp[i][j] = (s[i] == s[j]);
        else{
            if (s[i] == s[j]) return dp[i][j] = dp[i+1][j-1];
            else return false;
        }
        
    }
    void helper(int i, string &s , vector<string> &c, vector<vector<bool>> &dp){
        int n = s.size();
        // if( i == n ) {ans.push_back(c); return;} 
        
        for(int x = i ; x < n ; x++){
            if(palin(s,i,x,dp)){
                c.push_back(s.substr(i,x-i+1));
                if (x+1 < n )helper(x+1,s,c,dp);
                else ans.push_back(c);
                c.pop_back();
            }       
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        vector<string> c;
        helper(0,s,c,dp);
        
        return ans;
    }
};
