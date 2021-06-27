class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        auto a1 = lower_bound(a.begin(),a.end(),target) ;
        auto b = upper_bound(a.begin(),a.end(),target) ;
        
        if(a1==b)    return {-1,-1};
        
        auto beg = a.begin();
        
        return {int(a1-beg) , int(b-beg)-1};
            
         
    }
};
