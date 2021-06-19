int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> st;
        int ans = 0;
        int k = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') k++;
            else if(!k--) s[i] = '*', k = 0;
        }
        for(int i = n-1, k = 0 ; i > -1 ; i--){
            if(s[i] == ')') k++;
            else if(!k--) s[i] = '*', k = 0;
        }
        
        
        for(int i = 0 , start = 0; i < n ; i++){
            if(s[i] == '*') start = i+1;
            else ans = max(ans,i+1-start);
        }

        return ans;
    }
