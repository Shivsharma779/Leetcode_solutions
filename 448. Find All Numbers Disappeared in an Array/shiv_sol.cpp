class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
        int n = A.size();
        
        
        for(int i = 0; i < n; i++){
            if(abs(A[i]) <= n && abs(A[i]) > 0) 
                A[abs(A[i])-1] = -abs(A[abs(A[i])-1]);
            
            
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(A[i] >= 0) ans.push_back(i+1);
        }
        return ans;
        
    }
};
