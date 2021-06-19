int maxProduct(vector<int>& A) {
        int n = A.size();
        int ans = A[0];
        int xe = A[0] , ne = A[0];
        for(int i = 1 ; i < n ; i++){
            int a = A[i];
            if(a < 0) swap(xe,ne);
            xe = max(a,xe*a);
            ne = min(a,ne*a);
            
            ans = max(ans,xe);
        }
        return ans;
    }
