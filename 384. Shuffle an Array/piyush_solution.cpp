class Solution {
public:
    vector<int> original , shuff;
    Solution(vector<int>& nums) {
        original = shuff = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int k=0;k< shuff.size()/3 ; k++)
        {
            int i = rand() % shuff.size();
            int j = rand() % shuff.size();
            swap(shuff[i] , shuff[j]);
        }
        
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
