class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int correct_place = 1;
        int n = A.size();
        if(!n) return n;
        
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (A[j] != A[i]) {
                i++;
                A[i] = A[j];
            }
        }
        return i + 1;
        
    }
};
