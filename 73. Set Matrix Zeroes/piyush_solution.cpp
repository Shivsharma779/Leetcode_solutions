class Solution {
public:
    ///////////////////////////////////////////////////////////////////
    void m1_store_row_col_map(vector<vector<int>>& a) {
        int m=a.size() , n=a[0].size();
        unordered_map<int,bool> mp_row,mp_col;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==0)
                    mp_row[i] = mp_col[j] = true;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mp_row.find(i)!=mp_row.end() || mp_col.find(j)!=mp_col.end())
                    a[i][j]=0;
        
    }
    ///////////////////////////////////////////////////////////////////
    //https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
    void m2_store_row_col_matrix(vector<vector<int>>& a) 
    {        
        bool col0=false;
        int m=a.size() , n=a[0].size();   
        
        for(int i=0;i<m;i++)
        {
            if(a[i][0]==0)
                col0=true;
            
            for(int j=1;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    a[i][0]=a[0][j]=0; //store state of row and col in 1st row and col
                    //cout<<i<<" "<<j<<"\n";
        }   }    }
        
               
        //reverse traverse because changing 1st row will cause our 
        //stored values to be altered and output can change
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>0;j--)
            {
                if(a[i][0]==0 || a[0][j]==0)
                    a[i][j]=0;
            }
            
            if(col0)
                a[i][0]=0;
        }

}
    ///////////////////////////////////////////////////////////////////
    void setZeroes(vector<vector<int>>& matrix) {
        //m1_store_row_col_map(matrix);
        m2_store_row_col_matrix(matrix);
    }
};
