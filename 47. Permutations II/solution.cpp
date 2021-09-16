class Solution {
public:
    void helper(int i,vector<int> nums,vector<vector<int>> &res)
    {
        if(i==nums.size()-1)
            res.push_back(nums);
        else
        {
            
            for(int j = i;j<nums.size();j++)
            {
                if (i == j or nums[i] != nums[j]) 
                {
                    swap(nums[j],nums[i]);               
                    /*
                    for(auto x:nums)
                        cout<<x<<" ";
                    cout<<endl;
                    */
                    helper(i+1,nums,res);
                }               
                 
            }
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //set<vector<int>> mp;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        helper(0,nums,res);
        
        //vector<vector<int>> res(mp.begin(),mp.end());
        return res;
    }
};
