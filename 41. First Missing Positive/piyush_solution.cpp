class Solution {
public:
    void swap(int &a,int &b)
    {
        int t=a;
        a=b;
        b=t;
    }
    int firstMissingPositive(vector<int>& a) {
    
        int n=a.size(),j=0;
        
        for( int i=0;i<n;i++)
        {
            if(a[i]<=0)
            {
                swap(a[i],a[j]);
                j++;
            }
        }         
        
        for(int i=0;i<j;i++)
            a[i]=1;
        
        for(int i=j;i<n;i++)
        {
            if(abs(a[i])<=n && a[abs(a[i])-1]>0)
            {
                a[abs(a[i])-1] *= (-1);
            }
        }
        
        int i;
        for( i=0;i<n;i++)
            if(a[i]>0)
                return i+1;
        return i+1;
    }
};
