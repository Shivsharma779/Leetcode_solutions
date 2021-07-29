class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int n = M.size(), m =  M[0].size();
        bool frow = false;
        bool fcol  = false;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!M[i][j]){
                    M[i][0] = M[0][j] = 0;
                    if(!frow)frow =(i == 0)?1:0 ;
                    if(!fcol)fcol = (j== 0)?1:0;
                    
                    
                }    
            }
        }
    
        for(int i = 1 ; i< n ; i++){
            if(!M[i][0]){
                for(int j = 1 ; j < m ; j++) M[i][j] = 0;
            }
        }
        for(int j = 1 ; j< m ; j++){
            if(!M[0][j]){
                for(int i = 1 ; i < n ; i++) M[i][j] = 0;
            }
        }
        if(!M[0][0]){
            if(fcol) for(int i = 1; i < n ; i++) M[i][0] = 0;
            if(frow) for(int j = 1; j < m ; j++) M[0][j] = 0;
        }
        
    }
};
