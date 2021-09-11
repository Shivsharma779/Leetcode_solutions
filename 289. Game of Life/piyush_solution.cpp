class Solution {
public:
    bool issafe(vector<vector<int>>& board , int i,int j, int &m,int &n)
    {
        if(i>=0 && j>=0 && i<m && j<n && board[i][j])       //neighbour exists
            return true;
        return false;
    }
    /////////////////////////////////////////////////////////////////////////
    void m1_extra_space(vector<vector<int>>& board)
    {
        if(board.size()==0) return;
        int m=board.size() , n=board[0].size();
        vector<vector<int>> temp(board);
        
        
        vector<pair<int,int>> dirs;
        dirs.push_back({0,1});
        dirs.push_back({0,-1});
        dirs.push_back({1,0});
        dirs.push_back({-1,0});
        dirs.push_back({-1,-1});
        dirs.push_back({-1,1});
        dirs.push_back({1,1});
        dirs.push_back({1,-1});
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int neighbors = 0;
                for(auto dir:dirs)      //count neighbors
                    if(issafe(temp, i + dir.first  , j + dir.second ,m,n))
                        neighbors++;
                
                if(temp[i][j])  
                {
                    if(neighbors<2 || neighbors>3)
                        board[i][j]=0;
                    else 
                        board[i][j]=1;                        
                }
                else if(temp[i][j]==0 && neighbors==3)
                    board[i][j]=1;
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////
    
    //https://leetcode.com/problems/game-of-life/discuss/73230/C%2B%2B-O(1)-space-O(mn)-time
    //Since the board has ints but only the 1-bit is used, I use the 5th bit to store the new state. At the end, replace the old state with the new state by shifting all values one bit to the right.
    
    bool issafe2(vector<vector<int>>& board , int i,int j, int &m,int &n)
    {
        if(i>=0 && j>=0 && i<m && j<n && (1 & board[i][j]))       //neighbour exists
            return true;
        return false;
    }
    
    void m2_bitmanip(vector<vector<int>>& board)
    {
        if(board.size()==0) return;
        int m=board.size() , n=board[0].size();
        
        static vector<pair<int,int>> dirs{        {0,1},        {0,-1},        {1,0},        {-1,0},        {-1,-1},        {-1,1},        {1,1},       {1,-1}};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int neighbors = 0;
                for(auto dir:dirs)      //count neighbors
                    if(issafe2(board, i + dir.first  , j + dir.second ,m,n))
                        neighbors++;
                
                //cout<<neighbors<<" ";
                
                if((board[i][j] & 1) && (neighbors==2 || neighbors==3))  
                    board[i][j] |=  (1<<5);                        
                else if(!(board[i][j] & 1) && neighbors==3)
                    board[i][j] |=  (1<<5);
            }
            //cout<<"\n";
        }
        
        //0 or 1 based on markings
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                board[i][j] >>= 5;
    }
    /////////////////////////////////////////////////////////////////////////
    void gameOfLife(vector<vector<int>>& board) {
        //m1_extra_space(board);
        m2_bitmanip(board);
                
    }
};
