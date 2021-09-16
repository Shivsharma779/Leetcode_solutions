class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorall=0;
        for(auto &x:nums)
            xorall^=x;
        
        int msbset=0,i ;
        for(i=31;i>=0;i--)
            if(xorall & (1<<i))
                break;
        
        msbset = 1<<i;
        vector<int> res(2,0);
        
        
        //divide numbers based on whose msb(can be any other bit having 1) is set or not
        for(auto x:nums)
        {
            if(msbset & x)
                res[0] ^=x;
            else
                res[1] ^=x;
        }
        
        return res;
    }
};
/*
[1,2,1,3,2,5]

001
010
001
011
010
101

110

100
*/
