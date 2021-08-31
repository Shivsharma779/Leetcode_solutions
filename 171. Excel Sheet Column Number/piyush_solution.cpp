class Solution {
public:
    int titleToNumber(string s) {
        long long res=0,pow=1;
        
        for(int i=0;i<=s.size()-1;i++)
            res = res *26 + (s[i] - 'A' + 1);
        
        return res;
    }
};
