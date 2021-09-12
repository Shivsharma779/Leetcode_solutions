class Solution {
public:
    //https://www.youtube.com/watch?v=ey0d-EJ6gC0
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums.begin() , nums.end());
        sort(temp.begin() , temp.end());
        
        int j =temp.size()-1 , k=0 , n=temp.size();
        
        for(int i=1;i<n;i+=2)
            nums[i] = temp[j--];
        for(int i=0;i<n;i+=2)
            nums[i] = temp[j--];
    }
};
