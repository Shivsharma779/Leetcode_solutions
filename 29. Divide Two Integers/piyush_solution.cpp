class Solution {
public:
    //https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
    //see first comment also
    int divide(int a, int b) {
        if(a==b)
            return 1;
        if(a==0 || b==INT_MIN)  //max value divide gives 0 becuase of truncation
            return 0;
        if(a==INT_MIN && b==-1)     //-2^31 cannot be converted to positive so handle separately
                return INT_MAX;
        
        if(b==1)    return a;
        
        
        long res=0;
        bool neg = (a<0 ^ b<0);   
        
        long a1 = abs(a);
        long b1 = abs(b);
        
        //cout<<a<<" "<<b<<"\n";
        
        while(a1>=b1)
        {
            long temp = b1 , count=1;
            while(temp <= a1-temp)  //2*temp <= a1 
            {
                temp <<= 1;
                count <<= 1;
            }
            
            //cout<<a<<" "<<temp<<" "<<count<<"\n";
            
            a1 -= temp;
            res += count;
        }
        
        return neg ? -res : res;
    }
};
