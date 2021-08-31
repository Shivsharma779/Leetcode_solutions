class Solution {
public:
    int sq_sum_digit(int n)
    {
        int dig,sum=0;
        while(n)
        {
            dig = n%10;
            sum += (dig*dig);
            n/=10;
        }
        return sum;
    }
    //////////////////////////////////////////////////////////////////////////
    //https://leetcode.com/problems/happy-number/discuss/56919/Explanation-of-why-those-posted-algorithms-are-mathematically-valid
    int m2_cycle_detect(int n)
    {
        int fast=n,slow=n;
        do
        {
            fast = sq_sum_digit(sq_sum_digit(fast));
            slow = sq_sum_digit(slow);
            if(fast==1 || slow==1)
                return true;
        }while(fast != slow);
        
        return false;
    }
    //////////////////////////////////////////////////////////////////////////
    bool m1_umap(int n)
    {
        unordered_map<int,bool> mp;
        
        while(n!=1)
        {
            if(mp.find(n) != mp.end())
                return false;
            mp[n]=true;            
            n = sq_sum_digit(n);
        }
        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    /*
    All unhappy numbers follow sequences that eventually reach the eight-number cycle
    4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
    Reference:
    https://en.wikipedia.org/wiki/Happy_number
    */
    bool m3_math(int n)
    {
        while(n!=1)
        {
            if(n==4)
                return false;
            n = sq_sum_digit(n);
        }
        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool isHappy(int n) {
        //return m1_umap(n);
        //return m2_cycle_detect(n);
        return m3_math(n);
    }
};
