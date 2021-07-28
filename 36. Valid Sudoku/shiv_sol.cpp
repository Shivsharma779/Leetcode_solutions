 bool isValidSudoku(vector<vector<char>>& B) {
        bool R[9][9] = {0}, C[9][9] = {0} , S[9][9] = {0};

        
        bool ans = true;
        for(int i = 0 ; i < 9 ; i++){   
            for(int j = 0 ; j < 9 ; j++){
                if(B[i][j] != '.'){
                    int d = B[i][j] - '1';
                    int s = (3 * (i/3) + j/3);
                    // cout << B[i][j] << " ";
                    if(R[i][d] || C[d][j] || S[s][d] ) {
                        return ans = false;
                    }
                    R[i][d] = C[d][j] = S[s][d] = true;
                }
            }
            // cout << endl;
        }
        
         // return rows_correct(B) && cols_correct(B) && tt_correct(B);
        return ans;
    }
