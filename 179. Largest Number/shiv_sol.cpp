class Solution {
public:
    struct comp{
        bool operator()(const int & a, const int & b) const{
            string A = to_string(a), B = to_string(b);
            return A+B < B+A;
            return true;
        }    
    };
    
    string largestNumber(vector<int>& A) {
        sort(A.begin(),A.end(),comp());
        string ans;
        for(int i = A.size()-1; i > -1 ; i--) ans += to_string(A[i]);
        int i = 0;
        // cout << ans;
        while(i<ans.size()) if(ans[i++]!= '0') return ans;
        return "0";
    }
};
