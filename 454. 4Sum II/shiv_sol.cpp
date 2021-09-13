class Solution {
public:
    int fourSumCount(vector<int>& A1, vector<int>& A2, vector<int>& A3, vector<int>& A4) {
        // int n = A1.size();
        unordered_map<int,int> m;
        // sort(A4.begin() , A4.end());
        int ans = 0;
        for(auto &a: A1){
            for(auto &b : A2){
                m[a+b]++;
            }
        }
        for(auto &c :A3){
            for(auto &d : A4){
                auto x = m.find(0-c-d);
                if(x != m.end()){
                    ans += (x->second);
                }
            }
        }
        return ans;
    }
};
