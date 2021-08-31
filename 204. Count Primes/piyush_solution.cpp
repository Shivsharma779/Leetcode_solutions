class Solution {
public:
    int countPrimes(int n) {
        if(n<2)            return 0;
        vector<bool> sieve(n,true);
        int x = sqrt(n) , res=0;
        
        for(int i=2;i<=x;i++)
            if(sieve[i])
                for(int j=i*i ; j<n ; j+=i)
                    sieve[j]=false;
        
        for(int i=2;i<n;i++)
            if(sieve[i])
                res++;
        return res;
    }
};
