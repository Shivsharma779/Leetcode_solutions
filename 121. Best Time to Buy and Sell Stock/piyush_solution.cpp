class Solution {
public:
    int maxProfit(vector<int>& a) {
        int minprice = INT_MAX, maxprof = 0,t;
        
        for(int price:a)
        {
            minprice = min(minprice , price);
            maxprof = max(maxprof , price - minprice);
        }
                
        return maxprof;
    }
};
