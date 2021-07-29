class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0)    return 1;
        if(x==0)    return 0;
        if(n==-1)    return 1.0/x;
        
        double res=1;
        
        if(n>0)
        {
            n=-n;
            x=1.0/x;
        }
        
        res = myPow(x,n/2);
        
        if(n&1)
            res = (res*res*(1.0/x));
        else
            res *= res;
        
        return res;
        
    }
};
/*
4 2

1/4 -2      res = 16  

1/4  -1
    
*/ 
