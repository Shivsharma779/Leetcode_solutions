class Solution {
public:
    int maxProfit(vector<int>& P) {
        int ans = 0;
        for(int i = 1 ; i < P.size() ; i++){
            if(P[i] > P[i-1]) ans+= P[i] - P[i-1];
        }
        return ans;
    }
};
