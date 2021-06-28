class Solution {
public:
    
    int rob(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int ahead2 = 0;
        int ahead1 = 0;
        for(int i = n-1 ; i > -1 ; i--){
            
            ans = max(A[i] + ahead2 , ahead1);
            ahead2 = ahead1;
            ahead1 = ans;
            
        }
        return ans;
    }
};
