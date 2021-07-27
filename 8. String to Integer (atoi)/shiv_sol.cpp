class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        ss>> s;
        int ans = 0;
        bool neg = (s[0] == '-')?true:false;
        int i = (neg || s[0] == '+')?1:0;
        while(i<s.size() && isdigit(s[i])){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] - '0' > INT_MAX%10)){
                return (neg)?INT_MIN:INT_MAX;
                
            }
            ans = ans * 10 - '0' + s[i++];
        }
        
        return (neg)?-ans:ans;
    }
};
