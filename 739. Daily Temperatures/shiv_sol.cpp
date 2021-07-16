class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& A) {
        vector<pair<int,int>> s;
        
        int n = A.size();
        vector<int> ans(n,0);
        
        for(int i = n-1; i > -1; i--){
            while(!s.empty() && s.back().first <= A[i]) s.pop_back();
            ans[i] = (s.empty())?0:s.back().second-i;
            s.push_back({A[i],i});
        }
        return ans;
    }
};
