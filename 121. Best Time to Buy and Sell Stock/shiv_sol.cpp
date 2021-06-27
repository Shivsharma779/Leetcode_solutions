class Solution {
public:
    int maxProfit(vector<int>& p) {
     // min should be before max
        if(p.size() == 0) return 0 ;
        int cp = p[0], sp =p[0], n = p.size(), ans = 0;
        for (int i = 1 ; i < n ; i++){
            if(p[i] < cp) {
                if(ans < sp - cp) ans = sp - cp;
                cp = sp = p[i];
            }
            if(p[i] > sp) sp = p[i];
        }
        return (ans > sp - cp)? ans : sp - cp;
    }
};
