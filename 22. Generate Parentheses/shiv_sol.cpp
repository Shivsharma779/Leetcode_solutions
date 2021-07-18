class Solution {
public:
    vector<string> ans;
    void bracket(string s, int l, int r){
        if(r == 0) ans.push_back(s);
        
        if(l>0) bracket(s+"(",l-1,r);
        if(l<r) bracket(s+")",l,r-1);
        
    }
    vector<string> generateParenthesis(int n) {
        bracket("",n,n);
        return ans;
    }
};
