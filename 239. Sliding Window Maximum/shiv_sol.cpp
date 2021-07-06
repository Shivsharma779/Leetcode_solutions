class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> d;
        for(int i = 0 ; i < n ; i++){
            if(!d.empty() && d.front() < i-k+1) d.pop_front();
            if(!d.empty() && nums[d.back()] > nums[i]) d.push_back(i);
            else{
                while(!d.empty() && nums[d.back()] <= nums[i]) d.pop_back();
                d.push_back(i);
            }
            if(i>=k-1) ans.push_back(nums[d.front()]);

        }
        return ans;
    }
};
