class Solution {
public:
    int bsearch(vector<int>& a,int l , int r,int &target)
    {
        int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(a[mid]<target)     
                l=mid+1;
            else if(a[mid]>target)                        
                r=mid-1;
            else
                return mid;
        }
        return -1;
    }
        
    int search(vector<int>& nums, int target) 
    {
        //find smallest element in the array and do binary search accordingly
        int l=0,r=nums.size()-1,n=nums.size(),mid;
                
        while(l<r)
        {
            mid = (l+r)/2;
            if(nums[mid]>nums[n-1])     //pivot in right part
                l=mid+1;
            else                        //pivot in left part
                r=mid;
        }
        
        if(target>nums[n-1])
            return bsearch(nums,0 , l-1,target);
        else
            return bsearch(nums,l , n-1,target);        
    }
};
