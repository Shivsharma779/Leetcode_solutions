class Solution {
public:
    /////////////////////////////////////////////////////////////////////////////////
    void m1_reverse(vector<int>& nums, int &k)
    {
        k = k%(nums.size());    //if rotation more than arr size
        reverse(nums.begin() , nums.end());
        reverse(nums.begin()+k , nums.end());
        reverse(nums.begin() , nums.begin()+k);
    }
    /////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////
    void rotate(vector<int>& nums, int k) {
        m1_reverse(nums,k);
        
    }
};
