int m2_store_row_col_grid(const vector<string> &a)
{
    vector<vector<bool>> rhash(9,vector<bool>(9,false)),
                         chash(9,vector<bool>(9,false));
    vector<vector<vector<bool>>> ghash(3,vector<vector<bool>>(3,vector<bool>(9,false)));
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]!='.')
            {
                int num = a[i][j]-'0';
                if(rhash[i][num] || chash[j][num] || ghash[i/3][j/3][num])   
                    return false;
                
                rhash[i][num] = chash[j][num] = ghash[i/3][j/3][num] = true;
            }
        }
    }
    return true;
}
