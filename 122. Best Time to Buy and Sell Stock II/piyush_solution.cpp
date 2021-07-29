class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
                
        int t,maxprof=0;
        
        for(int i=1;i<n;i++)
        {
            t=a[i]-a[i-1];
            if(t>0)
                maxprof+=t;
        }    
        
        return maxprof;
    }
};
