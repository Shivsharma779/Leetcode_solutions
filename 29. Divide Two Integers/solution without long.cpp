class Solution {
public:
    //https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN)
        {
            if(divisor==-1) 
                return INT_MAX;
            else if(divisor==1)  
                return dividend;
            else 
                //                        INT_MIN+1 (can come in +ve int range) ,    //8/4 -> 4/2
                return ((divisor&1)==1) ? divide(dividend+1,divisor) : divide(dividend>>1,divisor>>1);
        } 
        
        if(divisor==INT_MIN) 
            return 0;
        
        int dvd = abs(dividend), dvs = abs(divisor), ans = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        while (dvd >= dvs) 
        {
            int temp = dvs, m = 1;
            while (temp <= dvd - temp) 
            {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
