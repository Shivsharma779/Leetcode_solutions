class Solution {
public:
    bool isvalid(int i , int j , int n , int m){
        // cout << i << " " << j << " " << n  << " "<< m << endl;
        if( j < 0 || i < 0 || i >= n || j >= m ) return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& B) {
        int n = B.size() , m = B[0].size();
        vector<pair<int,int>> dir{{-1,-1} ,{-1,0} ,{-1,1} , {0,-1} , {0,1} , {1,-1} , {1,0} , {1,1}};
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
                int an = 0 , dn = 0;
                
                for(pair<int,int> d : dir){
                    int ti= i+d.first , tj = j + d.second;
                    if( isvalid(ti,tj,n,m)){
                        if(B[ti][tj] == 1 || B[ti][tj] == 2) an++;
                        else dn++;
                    }
                }

                if(B[i][j] == 0){
                    if(an == 3) B[i][j] = -1;
                }
                else{
                    if(an < 2 || an > 3) B[i][j] = 2;
                }
            }
            // cout << endl;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(B[i][j] == -1) B[i][j] = 1;
                if(B[i][j] == 2) B[i][j] = 0;
               
            }
            
        }
    }
};
