class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        int n = A.size();
        int ans = 1;
        int current = 1;
        sort(A.begin() , A.end());
        for(int i = 0 ; i < n ; i++){
            current = 1;
            while(i < n-1 && (A[i+1] == A[i] ||A[i+1] == A[i]+1)) {
                
                if(A[i+1] == 1 + A[i]) current++;
                i++;
            }
            ans = max(current,ans);
        }
        return (n==0)?0:ans;
    }
};
