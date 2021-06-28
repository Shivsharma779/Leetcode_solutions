class Solution {
public:
    ///////////////////////////////////////////////////////////////////
    int m1_2array(vector<int>& a)
    {
        unsigned int n=a.size();
        if(n<3)
            return 0;
        int max;
        //int *lmax=(int*)malloc(sizeof(int)*n);
        //int *rmax=(int*)malloc(sizeof(int)*n);
        vector<int> lmax,rmax;
        
        lmax.push_back(0);
        max=a[0];
        for(int i=1;i<n;i++)
        {
            lmax.push_back(max);
            if(max<a[i])
                max=a[i];
        }
        
        max=a[n-1];
        rmax.push_back(0);
        for(int i=n-2;i>=0;i--)
        {
            rmax.push_back(max);
            if(max<a[i])
                max=a[i];
        }
        
        reverse(rmax.begin(),rmax.end());
        
        int vol=0;
        max=0;
        for(int i=1;i<n-1;i++)
            if(a[i]<min(lmax[i],rmax[i]))
                vol+=min(lmax[i],rmax[i]) - a[i];
        
        return vol;
    }
    ///////////////////////////////////////////////////////////////////
    int m2_2pointer(vector<int>& a)
    {
        //https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
        //read comments
        int n=a.size();
        int l=0,r=n-1;
        int maxl=0,maxr=0,res=0;
        
        while(l<=r)
        {
            if(a[l]<=a[r])
            {
                if(maxl<a[l])
                    maxl = a[l];
                else
                    res += (maxl - a[l]);
                l++;
            }
            else
            {
                if(maxr<a[r])
                    maxr = a[r];
                else
                    res += (maxr - a[r]);
                r--;
            }
        }
        return res;
    }
    
    int trap(vector<int>& a) {
        //return m1_2array(a);
        return m2_2pointer(a);
        
    }
};
