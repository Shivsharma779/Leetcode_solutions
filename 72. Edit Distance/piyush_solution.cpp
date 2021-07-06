class Solution {
public:
    //O(n^2) time, O(n) space
    int minDistance(string w1, string w2) {
        
        
        int m=w1.size(),n=w2.size();
        if(m==0)
            return n;
        if(n==0)
            return m;
        
        
        vector<int> dp1(n+1),dp2(n+1);
        
        for(int i=0;i<=n;i++)
            dp1[i]=i;
        
        for(int i=1;i<=m;i++)
        {
            dp2[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(w1[i-1]==w2[j-1])
                    dp2[j]=dp1[j-1];
                else
                    dp2[j]=min(dp1[j-1],min(dp1[j],dp2[j-1]))+1;
            }
            dp1=dp2;            //copy dp1 to dp2
        }
        
        return dp2[n];
    }
};
