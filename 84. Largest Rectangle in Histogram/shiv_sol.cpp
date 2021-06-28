class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        vector<int> st;
        for (int i = 0 ; i <= n; i++ ){
            while(!st.empty() && (i == n || A[st.back()] > A[i] )){
                int t = A[st.back()];
                
                int prev = 0;
            
                st.pop_back();
                if(!st.empty()) prev = st.back() + 1;

                
                
                ans = max(ans, t * (i - prev)  );
                
            }
            st.push_back(i);
        }
        
      
        return ans;
        
        
    }
};
