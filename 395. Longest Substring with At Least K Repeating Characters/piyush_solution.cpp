class Solution {
public:
    //https://www.youtube.com/watch?v=5QpMpO2CAb0
    int longestSubstring(string s, int k) {
        return helper(s,0 , s.size()-1 , k);
    }
    
    int helper(string &s, int st , int ed , int &k)
    {
        int freq[26]={};
        for(int i=st;i<=ed;i++)
            freq[s[i]-'a']++;
        
        for(int i=st;i<=ed;i++)
        {
            if(freq[s[i]-'a'] < k)
            {
                int j=i+1;
                while(j<=ed && freq[s[j]-'a']<k)    //skip chars having freq less than k
                    j++;
                
                //
                return max(helper(s,st,i-1,k) , helper(s,j,ed,k));
            }
        }
        
        return ed-st+1;
    }
        
};

/*
aaabaaabaaa   k=3

aaa aaabaaa
    

*/

