class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i , j ,k;
        for(k = n + m -1, i = m-1 , j = n-1 ; i > -1 && j > -1;){
            if(A[i] > B[j]){
                A[k] = A[i--];
            }
            else{
                A[k] = B[j--];
            }
            k--;
        }
        while(i > -1){
            A[k] = A[i--] , k--;
        }
        while(j > -1){
            A[k] = B[j--] , k--;
        }
        
    }
};
