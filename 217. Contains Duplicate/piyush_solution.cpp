class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto x:nums)
            mp.insert(x);

        return nums.size() > mp.size();
            
    }
};
