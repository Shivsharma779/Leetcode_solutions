class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int n = A.size();
        int start = 1;
        int end = 1;
        vector<int> ans(n,1);
        
        
        for(int i =0 ; i < n; i ++){
            ans[i] = ans[i]*start;
            start *= A[i];
        }
        for(int i =n-1 ; i > -1; i--){
            ans[i] = ans[i]*end;
            end *= A[i];
        }
        return ans;
        
    }
};
