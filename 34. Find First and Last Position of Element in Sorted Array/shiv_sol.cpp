class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //greater or equal
        auto a = lower_bound(nums.begin(), nums.end(), target);
        //greater
        auto b= upper_bound (nums.begin(), nums.end(), target);
        
        if(a == b) return {-1,-1};
        else {
            int l  = a-nums.begin() , h = b-nums.begin();
            return {l , --h};
        }
    }
};
