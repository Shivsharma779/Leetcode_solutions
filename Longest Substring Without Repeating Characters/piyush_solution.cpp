class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int n=a.size(),i,j;
        
        int maxl=0,st=-1;
        vector<int> fr(256,-1);
        
        for(int i=0;i<n;i++)
        {
            if(fr[a[i]]>st)
                st=fr[a[i]];
            fr[a[i]]=i;
            maxl=max(maxl,i-st);
        }
        
        return maxl;
        
    }
};
