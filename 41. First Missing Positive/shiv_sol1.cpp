class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; i++){
         if(A[i] <= 0) A[i] =INT_MAX;   
        }
        for(int i = 0; i < n; i++){
            if(abs(A[i])-1 > -1 && abs(A[i])-1 < n) A[abs(A[i])-1] = -(abs(A[abs(A[i])-1]));
        }
        for(int i =0 ; i < n; i++){
            
            if(A[i] >= 0) return i+1;
        }
        return n+1;
        
    }
};
