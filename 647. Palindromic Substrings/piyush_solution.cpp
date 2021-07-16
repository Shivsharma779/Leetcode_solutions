class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        
        if(n==0 || n==1)
            return n;
        
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            
            //odd len
            int j=0;
            while((i-j)>=0 && (i+j)<n && s[i-j]==s[i+j])
            {
                c++;
                j++;
            }
            
            //even len
            j=0;
            while((i-j)>=0 && (i+j+1)<n && s[i-j]==s[i+j+1])
            {
                c++;
                j++;
            }
        }
        return c;
    }
};
