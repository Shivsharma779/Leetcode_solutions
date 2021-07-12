class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        
        long long res=1;
        int num=n+1,den=1;
        while(num<=2*n)
        {
            res*=num;
            res/=den;
            num++;
            den++;
        }
        res/=den;
        return res;
    }
};
