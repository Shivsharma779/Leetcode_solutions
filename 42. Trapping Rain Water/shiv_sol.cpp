class Solution {
public:
    int trap(vector<int>& A) {
        vector<pair<int,int>> st;
        int n = A.size();
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(st.empty() || st.back().first > A[i]) st.push_back({A[i],i});

            else{
                int mt = 0;

                while(!st.empty()){
                    int h = st.back().first, j = st.back().second;

                    // cout <<A[i] << " " << i << " " <<  h << " " << j << endl;
                    ans += ( min(h-mt,A[i]-mt) * (i-j-1) );
                    mt = h;
                    // cout <<  ans << endl;

                    if(h > A[i])    break;
                    else st.pop_back();
                }

                st.push_back({A[i],i});
            }

        }
        
        
        
        return ans;
        
        
    }
};
