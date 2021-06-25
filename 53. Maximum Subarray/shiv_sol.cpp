class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gm = INT_MIN; int cm = 0;
        for(auto a:nums){
            
            cm = cm+a;
            
            // cout << a << " " << cm << "\n";
            if(cm > gm) gm=cm;
            if(cm < 0) cm = 0;
        }
        return gm;
    }
};
