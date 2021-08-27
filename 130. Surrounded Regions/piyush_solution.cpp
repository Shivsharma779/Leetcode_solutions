class Solution {
public:
    //https://leetcode.com/problems/surrounded-regions/discuss/41612/A-really-simple-and-readable-C%2B%2B-solutionuff0conly-cost-12ms
    void print_arr(vector<vector<char>>& a,int &m,int &n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
    bool issafe(int i,int j,vector<vector<char>>& board,int &m,int &n)
    {
        if(i>=0 && j>=0 && i<m && j<n && board[i][j]=='O')
            return true;
        return false;
    }
    void check_borders(int i,int j,vector<vector<char>>& board,int &m,int &n)
    {
        board[i][j]='M';
        
        if(issafe(i+1,j,board,m,n))
            check_borders(i+1,j,board,m,n);     
            
        if(issafe(i-1,j,board,m,n))
            check_borders(i-1,j,board,m,n);

        if(issafe(i,j+1,board,m,n))
            check_borders(i,j+1,board,m,n);
            
        if(issafe(i,j-1,board,m,n))
            check_borders(i,j-1,board,m,n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0)
            return;
        int n=board[0].size();
        
        //print_arr(board,m,n);
        //cout<<"\n";
        
        //mark all border connected rgions as 'M'
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                check_borders(i,0,board,m,n);         //left-most col
            if(board[i][n-1]=='O')
                check_borders(i,n-1,board,m,n);       //right-most col
        }    
        
        //print_arr(board,m,n);
        //cout<<"\n";
        
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
                check_borders(0,j,board,m,n);         //top row
            if(board[m-1][j]=='O')
                check_borders(m-1,j,board,m,n);       //bottom row
        } 
        
        //print_arr(board,m,n);
        
        // 'M' marked regions are border so reverted to 'O'
        // 'O' marked regions are not connected to border so they ar surrounded. Hence converted to 'X'
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='M')        //border marked 'O'
                    board[i][j]='O';
                else if(board[i][j]=='O')        //non-border marked 'X'
                    board[i][j]='X';     
        
    }
};
