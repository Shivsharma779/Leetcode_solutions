class Solution {
public:
    
    int maximalRectangle(vector<vector<char>>& M) {
        int n = M.size(); 
        if(!n) return 0;
        int m = M[0].size();
        if(!m) return 0;
        int ans = 0;
        for(int j = 0 ; j < m ; j++){
            
            vector<int> st;
            for(int i = 0 ; i <= n; i++){
                // cout << i << j << endl;
                if(i < n && M[i][j] == '0') WS[i] = j;
                
                
                while(!st.empty() && (i == n || j - WS[i] <=  j - WS[st.back()] ) ){
                    int t = st.back();
                    st.pop_back();
                    int ws = j - WS[t];
                    int start_l = (st.empty())?-1:st.back();
                    int ls = i - (start_l + 1);

                    
                    ans = max(ans,ls*ws);
                }
                st.push_back(i);
            }
            
            
        }
        return ans;
        

    }
};
