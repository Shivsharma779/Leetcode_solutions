class Solution {
public:
    int n , m;
    vector<pair<int,int>> dir;
    bool isvalid(int i ,int j){
        if(i<0 || i>= n || j < 0 || j >=m ) return false;
        return true;
    }
    bool checkbounddary(int i , int j){
        if(i == 0 || i == n-1 || j == 0 || j == m-1) return true;
        return false;
    }
    void helper(int i , int j ,vector<vector<char>>& B){
        B[i][j] = '-';
        for(auto d : dir){
            int ti = i+d.first, tj = j+d.second;
            
            if(isvalid(ti,tj)  && B[ti][tj] == 'O'){
                helper(ti,tj,B);
            }
        }
        
    }
    void solve(vector<vector<char>>& B) {
        n = B.size(), m = B[0].size();
        dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ;j < m ; j++){
                if(B[i][j] == 'O' && checkbounddary(i,j)){
                    
                    helper(i,j,B);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ;j < m ; j++){
                if(B[i][j] == '-'){
                    B[i][j] = 'O';
                }
                else{
                    B[i][j] = 'X';
                }
              
            }
         
        }
        
    }
};
