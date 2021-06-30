class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        int n = A.size();
        int p ,ans = 0, sum = 0;
        unordered_map<int,int> m{{0,1}};
        
        for(auto &a: A){
            sum += a;
            p = sum - k ;
            if(m.find(p)!=m.end())
                ans+=m[p];
            m[sum]++;
        }
        return ans;
    }
};
