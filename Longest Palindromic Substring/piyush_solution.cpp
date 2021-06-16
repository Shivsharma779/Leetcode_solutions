class Solution {
public:
    
    string approach1_dp(string &s)
    {
        int n=s.size(),maxl=0;
        string res="";
        vector<vector<bool>> dp( n , vector<bool> (n, false));
        
        if(n==0)
            return res;
        
        res=s[0];
        maxl=1;        
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                if(maxl<2)          //save max len string
                {
                    maxl=2;
                    res = s.substr(i,2);
                }
            }
        }
        
        for(int j=2;j<n;j++)            //len of substr
        {
            for(int i=0;i<n-j;i++)
            {
                if(s[i]==s[i+j] && dp[i+1][i+j-1])
                {
                    dp[i][i+j]=true;
                    if(maxl < j+1)
                    {
                        maxl=j+1;
                        res = s.substr(i,j+1);
                    }
                }
            }
        }
            
        return res;
    }
    
    //////////////////////////////////////////////////////////////////////
    //https://www.youtube.com/watch?v=y2BD4MJqV20
    string approach2_expand(string &s)       //time = O(n2) , space = O(1)
    {
        int start=0,end=0,pal1,pal2,len;      //start and end of required string
        
        for(int i=0;i<s.size();i++)
        {
            pal1 = expandPalindrome(s,i,i);     //odd len palindrome
            pal2 = expandPalindrome(s,i,i+1);   //even len palindrome
            len = max(pal1,pal2);
            
            if(len > end-start+1)         //larger length palindrome
            {
                start = i - (len-1)/2;
                end = i + (len/2);
                //cout<<start<<" "<<end<<"\n";
            }
        }
        
        return s.substr(start , end-start+1);
    }
    
    int expandPalindrome(string &s , int l, int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }        
        return r-l-1;       //both pointers will be one off from req palindrome
    }
    
    //////////////////////////////////////////////////////////////////////
    string longestPalindrome(string &s) 
    {
        //return approach1_dp(s);
        return approach2_expand(s);     
    }
};
