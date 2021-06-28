class Solution {
public:
    int rob(vector<int>& a) {
        
        int n=a.size();
        if(n==0)
            return 0;
        if(n==1)
            return a[0];
        
        a[1]=max(a[0],a[1]);
        
        for(int i=2;i<n;i++)
            a[i]=max(a[i-1],a[i-2]+a[i]);           
        return a[n-1];
    }
};
