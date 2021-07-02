class Solution {
public:
    
    int m1_dp(int &n)
    {
        static vector<int> dp(10001,INT_MAX);       //make it static so that calculation has to be done only once
        static bool f=true;     //true only in first test case
        
        if(f)
        {
            f=false;
            dp[0]=0;

            for(int i=1;i<10001;i++)
                for(int j=1; j*j<=i ;j++)
                    dp[i] = min(dp[i] , dp[i - j*j]+1);
        }
        
        return dp[n];
    }
    
    //https://leetcode.com/problems/perfect-squares/discuss/707526/Python-Fastest-O(sqrt(n))-solution-with-math-explanied.
    
    //any number can be represented as sum of 4 squares:1, 2, 3 or 4
    //O(logn ^ 2)
    int m2_math(int &n)
    {
        //to check that number is sum of 4 squares , prove that a positive integer can be expressed as the sum of three squares if and only if it is not of the form 4^k(8m+7) for integers k and m
        while( n % 4 == 0) 
            n >>= 2;
        if( n % 8 == 7)
            return 4;
        
        //below conditions  work with updated value of n vecause 4 is perfect square 
        
        //check if number is full square?
        int sq = sqrt(n);
        if( sq*sq == n)
            return 1;
        
        //to check if number is sum of 2 squares: n = i*i + j*j,  iterate ovell all i < sqrt(n) and check that n - i*i is full square. Complexity of this part is O(sqrt(n)).
        for(int j=0; j<=sq ; j++)
        {
            int sq2 = sqrt(n - j*j);
            if(sq2*sq2 == n - j*j)
                return 2;
        }

        return 3;
    }
    
    int numSquares(int n) {
        //return m1_dp(n);
        return m2_math(n);

    }
};
