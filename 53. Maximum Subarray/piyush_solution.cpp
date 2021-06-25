class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int cmax,gmax,n=a.size();
        if(n==0)            return 0;
        
        cmax=gmax=a[0];
        for(int i=1;i<n;i++)
        {
            cmax=max(a[i],(cmax+a[i]));        
            gmax=max(gmax,cmax);
        }
        return gmax;
    }
};
