class Solution {
public:
    map<pair<int,int>,string> m;
    string helper(string &s, int st,int e){
        if(st < 0 || e > s.size() ) return "";
        auto x = m.find({st,e});
        if( x!= m.end()) return x->second;
        if(s[st] == s[e]){
            string x = helper(s,st-1,e+1);
            if(x != "") return x;
            else return m[{st,e}] = s.substr(st,e+1-st);
        }
        return "";
    }
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            string odd = helper(s,i,i);
            string even = helper(s,i,i+1);
            ans = (ans.size() < odd.size())? odd: ans;
            ans = (ans.size() < even.size())? even: ans;
        }
        return ans;
    }
};
