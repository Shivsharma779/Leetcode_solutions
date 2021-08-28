class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0,hi=nums.size()-1,l,r;
        
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            l=(mid==0)?INT_MIN:nums[mid-1];
            r=(mid==nums.size()-1)?INT_MIN:nums[mid+1];
            
            if(nums[mid]>l && nums[mid]>r)
                return mid;
            else if(l>nums[mid])
                hi=mid-1;
            else
                lo=mid+1;
        }
        
        return lo;
    }
};
