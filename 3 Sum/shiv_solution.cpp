class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() ; i++){
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                int sum = nums[low]+nums[high] +nums[i];
                
                if(sum == 0){
                    vector<int> x{nums[low],nums[high],nums[i]};
                    sort(x.begin(),x.end());
                    result.insert(x);
                    low++,high--;
                }
                else if(sum>0){
                    high--;
                }else{
                    low++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto a: result) ans.push_back(a);
        return ans;
    }
};
