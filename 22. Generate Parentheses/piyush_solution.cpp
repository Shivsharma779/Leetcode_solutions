class Solution {
public:
    void helper(int open,int close,int &n,vector<string> &res,string &cur)
    {
        if(open==close and open==n)
            res.push_back(cur);
        
        if(open<n)
        {
            cur+='(';
            helper(open+1,close,n,res,cur);
            cur.pop_back();
        }
        
        if(close<n && close<open)
        {
            cur+=')';
            helper(open,close+1,n,res,cur);
            cur.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur="";
        helper(0,0,n,res,cur);
        return res;
    }
};
