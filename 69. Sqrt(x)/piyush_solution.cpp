class Solution {
public:
    int mySqrt(int x) {
        long long i=0,j=x,res=0,m;
        while(i<=j)
        {
            m = i + (j-i)/2;
            if(m*m == x)
                return m;
            else if(m*m < x)
            {
                res=m;
                i=m+1;
            }
            else
                j=m-1;
        }
        return res;
    }
};
