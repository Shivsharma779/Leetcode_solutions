class Solution {
public:
    bool wordBreak(string s, vector<string>& dic) {
        unordered_map<string,bool> mp;
        
        for(auto s:dic)             //dictionary of words
            mp[s]=true;
        
        
        int i=0,j=0,n=s.size();
        vector<int> dp(n+1,false);      //dp array where ith entry suggests if word 
                                        //break possible till ith length of s
        dp[0]=true;                     //empty string can always be broken
        
        for(int len=1;len<=n;len++)     //for length 1 to n
        {
            for(int j=len-1;j>=0;j--)   // try to break string at (i-1)th to 0th index
            {
                if(dp[j] && mp.find(s.substr(j,len-j))!=mp.end())   
                {
                    dp[len]=true;   //if word break possible till jth index and 
                                    //after that there is substring that is in 
                                    //dictionary
                    break;
                }
            }
        }
        
        return dp[n];
        
    }
};
