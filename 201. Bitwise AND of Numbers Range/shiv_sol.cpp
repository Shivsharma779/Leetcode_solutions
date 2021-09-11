class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)
            return left;
        
        int res=0;
        bool msbflag=false;
        
        for(int i=31;i>=0;i--)
        {
            if((left&(1<<i)) or (right&(1<<i)))
                msbflag=true;
            
            if(msbflag)
            {
                if((left & (1<<i)) and (right & (1<<i)))
                    res |= (1<<i);
                else if(!(left & (1<<i)) and !(right & (1<<i)))
                    continue;
                else
                    break;
            }
        }
        
        return res;
    }
};
