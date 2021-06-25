public:
    bool helper(int i , int j , int k, vector<vector<char>> &B , string &s ){
        int n = B.size(), m = B[0].size() ,  o = s.size();
        
        if ( k == o) return  true;
        if ( i > n-1 || i < 0 || j > m-1 || j < 0 || B[i][j] != s[k]) return false;
        
        
        
        
        k++;
        char t = B[i][j];
        B[i][j] = '*';
        
        bool with = helper(i+1,j,k,B,s) || helper(i-1,j,k,B,s) || helper(i,j-1,k,B,s) ||helper(i,j+1,k,B,s);
        B[i][j] = t;
        
        return  with;
        
    }
    bool exist(vector<vector<char>>& B, string &s) {
        int n = B.size(), m = B[0].size() ,  o = s.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(s[0] == B[i][j] && helper(i,j,0,B,s)) return true;
            }
        }
        return false;
    }
};
