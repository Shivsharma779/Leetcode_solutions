class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int x =(n%2)?n+1:n;
        
        for(int i = 0; i < x/2; i++){
            for(int j = 0; j < n/2; j++){

                
                int temp = m[i][j];
                m[i][j] = m[n-1-j][i]; // 00 <= 30
                m[n-1-j][i] = m[n-1-i][n-1-j]; // 30 <= 33
                m[n-1-i][n-1-j] = m[j][n-1-i]; // 33 <= 03
                m[j][n-1-i] = temp;
                
            }
        }
    }
};
