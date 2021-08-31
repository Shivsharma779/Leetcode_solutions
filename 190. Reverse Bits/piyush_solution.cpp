class Solution {
public:
    uint32_t m1_temp_var(uint32_t n)
    {
        //reverse in another number and return
        uint32_t x=0;
        for(int i=0;i<32;i++)
            if((1<<(32-i-1)) & n) 
                x |= (1<<i);
        
        return x;
    }
    uint32_t m2_inplace(uint32_t n)
    {
        /*
        use left and right pointer approach, four cases:
        do nothing in these cases
        1__1
        0__0
        
        need to handle below cases
        1__0
        0__1        
        
        */
        for(int i=0;i<16;i++)
        {
            //cout<<(bool)((1<<i)&n) << " " <<(bool)((1<<(32-i-1))&n)<<" ";
            if((bool)((1<<i)&n) ^ (bool)((1<<(32-i-1))&n))  //xor means both bits are diff
            {
                //invert these bits
                //cout<<i<<" \n";
                n = n^(1<<i);
                n = n^(1<<(32-i-1));
            }
        }
        
        return n;
    }
    uint32_t reverseBits(uint32_t n) {
        return m1_temp_var(n);
        //return m2_inplace(n);
    }
};
