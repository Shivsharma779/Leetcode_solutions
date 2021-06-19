class Solution {
public:
    //https://www.youtube.com/watch?v=lLFDQCDzfpI
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size())       //we iterate over smaller array
            return findMedianSortedArrays(nums2,nums1);
        
        int l=0,r=nums1.size(),totlen = nums1.size()+nums2.size();
        int partx,party,leftx,lefty,rightx,righty;
        
        while(l<=r)
        {            
            partx = (l+r)/2;
            party = (totlen+1)/2 - partx;
             
            leftx = (partx==0) ? INT_MIN : nums1[partx-1];
            lefty = (party==0) ? INT_MIN : nums2[party-1];
            
            rightx = (partx==nums1.size()) ? INT_MAX : nums1[partx];
            righty = (party==nums2.size()) ? INT_MAX : nums2[party];
            
            if(leftx > righty)
                r = partx - 1;
            else if(lefty > rightx)
                l = partx + 1;
            //keep this condition at last because it has may operators and checking every time will slow down the code. Also this runs only once so no need to run every time
            else if((leftx <= righty) && (lefty <= rightx))     
            {
                if(totlen&1)        //odd total length
                    return max(leftx , lefty);
                else
                    return (double)(max(leftx , lefty) + min(rightx , righty))/2.0;
            }
            
        }
        
        return 0;     
    }
};
