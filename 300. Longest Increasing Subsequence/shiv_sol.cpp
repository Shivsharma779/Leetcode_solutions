static auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i  =n-1 ; i >= 0 ; i--){
            for(int j = i ; j < n ;j++){
                if(nums[j] > nums[i]) dp[i] = max(dp[i], dp[j] +1);
            }
        }
        int ans = -1;
        for(int a: dp) ans = max(ans,a);
        return ans+1;
        
    }
};
