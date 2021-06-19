class Solution {
public:
    int maxProduct(vector<int>& a) {
        int gmax,cmax,n=a.size(),cmin;
        
        if(n==0)
            return 0;
        
        cmin=gmax=cmax=a[0];
        
        for(int i=1;i<n;i++)
        {
            int temp = cmax;        //store cmax for use in cmin calcualtion
            cmax = max(a[i],max(cmax*a[i],cmin*a[i]));  //
            cmin = min(a[i],min(temp*a[i],cmin*a[i]));
            gmax = max(gmax,cmax);    
        }
        return gmax;
    }
};
