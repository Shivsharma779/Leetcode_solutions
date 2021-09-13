class Solution {
public:
    vector<int> a;
    vector<int> b;
    Solution(vector<int>& nums) {
        a=nums;
            b = (nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
     return b;   
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = a.size();
        if(n < 2) return a;
        for(int i = n-1 ; i > -1 ; i--){
            
            int ind = rand()%(i+1);
            swap(a[ind],a[i]);
        }
        return a;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
