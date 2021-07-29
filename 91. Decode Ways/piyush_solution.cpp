class Solution {
public:
    //https://www.youtube.com/watch?v=cQX3yHS0cLo
    int numDecodings(string s) {
        int n=s.size();
        int dp[n+1];
        dp[0]=1;        //empty string has one way to decode
        dp[1]=(s[0]=='0') ? 0 : 1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=0;
            int one_digit = s[i-1] - '0';
            int two_digit = (s[i-2]-'0')*10 + one_digit;
                        
            if(one_digit>0)         //current digit not 0
                dp[i] += dp[i-1];
            
            if(two_digit >=10 && two_digit <=26)    //last two digit form valid number
                dp[i] += dp[i-2];
        }
            
        return dp[n];
    }
};
