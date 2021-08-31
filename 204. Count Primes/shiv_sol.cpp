class Solution {
public:
    
    int countPrimes(int n) {
        if (n == 0) return 0;
        vector<bool> isprime(n,true);
        isprime[0] = isprime[1] = false;
        int ans = 0;
        for(int i =2 ; i < n ; i++){
            if(isprime[i]){
                int j = 2;
                ans++;
                while(i*j < n) isprime[i*j] = false, j++;
            }
        }
        return ans;
    }
};
