class Solution {
public:
    vector<string> result;
    void helper(int x, string &y, string &s , unordered_set<string> &st){
        int n = s.size();
        if(x == n) result.push_back(y);
        string curr;
        for(int i = x; i < n; i++){
            curr.push_back(s[i]);
            // cout << curr << endl;
            if(st.find(curr) != st.end()){
                string p = y;
                y = y + curr;
                y = (i == n-1)?y:y+" ";
                helper(i+1,y,s,st);
                y = p;
            } 
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& W) {
        unordered_set<string> st(W.begin , W.end());
        string curr = "";
        helper(0,curr,s,st);
        
        return result;
    }
};
