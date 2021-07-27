class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(nums.size() > 1){
           int slow = nums[0];
           int fast = nums[nums[0]];
           
           while(slow != fast){
               slow = nums[slow];
               fast = nums[nums[fast]];
           }
           
           slow = 0;
           while(slow != fast){
               slow = nums[slow];
               fast = nums[fast];
           }
           
           return fast;
       }
        return -1;
    }
    
};
