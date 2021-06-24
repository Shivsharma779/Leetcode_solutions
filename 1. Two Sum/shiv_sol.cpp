class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(auto i = nums.begin(); i!=nums.end(); i++){
            int val = target - *i;
            m.insert({*i,i-nums.begin()});
            map<int,int>::iterator it;
            if((it = m.find(val)) != m.end() && i-nums.begin() != it->second)
                return{(int)(i-nums.begin()), (int)(it->second)};
           
        
            
             
        }
        return {};
        
    }
};
