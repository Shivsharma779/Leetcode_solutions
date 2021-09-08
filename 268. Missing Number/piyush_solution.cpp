class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(auto &x:nums)
            x++;
        
        for(int i=0;i<nums.size();i++)
            if(abs(nums[i]) - 1 < nums.size())
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        
        for(int i=0;i<nums.size();i++)
        {
            //cout<<nums[i]<<" ";
            if(nums[i]>=0)
                return i;
        }
        return nums.size();
    }
};
