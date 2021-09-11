class Solution {
public:
    //https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78993/Clean-and-short-with-comments-C%2B%2B
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX , b=INT_MAX;
        for(auto x:nums)
        {
            if(x<=a)
                a=x;
            else if(x<=b)
                b=x;
            else 
                return true;
        }
        return false;
    }
};
