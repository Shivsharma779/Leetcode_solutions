class Solution {
public:
    bool increasingTriplet(vector<int>& A) {
        int n = A.size();

        
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            // cout << m1 << " " << m2 << " " << A[i] << endl;
            if(A[i] <= m1 ) m1 = A[i];
            else if(A[i] <= m2 ) m2 = A[i];
            else return true;
        }
        return false;
    }
};
