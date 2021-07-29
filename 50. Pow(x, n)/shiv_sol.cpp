class Solution {
public:
    double myPow(double x, long long int n) {
        if(n == 1) return x;
        if(n == 0) return 1;
        
        if(x == 1) return 1;
        if(x == 0) return 0;
        if(n == INT_MIN) n = n/2 , x = x*x;
        if(n < 0) x = 1/x , n = -n;
        
        double half = myPow(x,n/2);
        if(n%2) return x*half * half;
        else return half*half;
    }
};
