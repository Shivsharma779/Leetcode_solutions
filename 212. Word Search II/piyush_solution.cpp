class trienode{
    public:
    vector<trienode*> child;
    bool isword = false;
    
    trienode()
    {
        child = vector<trienode*>(26,0);
    }
};
//////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    //////////////////////////////////////////////////////////////////////////////
    trienode* insert_trie(trienode *root , string s)
    {
        trienode *cur = root;
        for(int i=0;i<s.size();i++)
        {            
            if((cur->child)[s[i]-'a'] == 0)        //new char
            {
                (cur->child)[s[i]-'a'] = new trienode();
                //cout<<s[i]<<" ";
            }            
            cur = (cur->child)[s[i]-'a'];
        }
        //cout<<"\n";
        cur->isword = true;
        return root;
    }
    //////////////////////////////////////////////////////////////////////////////
    bool issafe(int i, int j,vector<vector<char>>& board)
    {
        int m=board.size() ,  n=board[0].size();
        if(i>=0 && j>=0 && i<m && j<n && board[i][j] != '0')
            return true;
        return false;
    }
    //////////////////////////////////////////////////////////////////////////////
    void search_board(int i, int j,vector<vector<char>>& board,vector<string> &res, trienode *root, string s)
    {
        //cout<<s<<" ";
        
        if(root->isword)
        {
            res.push_back(s);
            root->isword = false;
            //dont return here as there maybe other words in same chain
        }
        
        //mark visited
        char temp = board[i][j];
        board[i][j]='0';
        
        
        if(issafe(i,j+1,board) && (root->child)[board[i][j+1]-'a'])
            search_board(i , j+1 , board , res , (root->child)[board[i][j+1] - 'a'] ,  s+board[i][j+1]);
        
        if(issafe(i+1,j,board) && (root->child)[board[i+1][j]-'a'])
            search_board(i+1 , j , board , res , (root->child)[board[i+1][j] - 'a'] ,  s+board[i+1][j]);
        
        if(issafe(i,j-1,board) && (root->child)[board[i][j-1]-'a'])
            search_board(i , j-1 , board , res , (root->child)[board[i][j-1] - 'a'] ,  s+board[i][j-1]);
        
        if(issafe(i-1,j,board) && (root->child)[board[i-1][j]-'a'])
            search_board(i-1 , j , board , res , (root->child)[board[i-1][j] - 'a'] ,  s+board[i-1][j]);
        
        //unmark visited on return 
        board[i][j]=temp;
            
    }
    //////////////////////////////////////////////////////////////////////////////
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m=board.size();
        if(m==0)
            return res;
        
        int n = board[0].size();
        trienode *root = new trienode();
        /*
        string s ="hemlo";
        root = insert_trie(root , s);
        root = insert_trie(root , "hellobss");
        root = insert_trie(root , "hellopuss");
        
        s = "hellobss";
        trienode *cur = root;
        int i;
        for(i=0;i<s.size();i++)
        {
            
            if((cur->child)[s[i]-'a'] == 0)
            {
                cout<<"not found "<<s.substr(0,i)<<"\n";
                break;
            }
            cur = (cur->child)[s[i]-'a'];
        }
        if(cur->isword)
        {    
            cout<<"found "<<s.substr(0,i)<<"\n";
            cur->isword=false;
        }
                
        s = "hellopuss";
        cur = root;
        for(i=0;i<s.size();i++)
        {
            
            if((cur->child)[s[i]-'a'] == 0)
            {
                cout<<"not found "<<s.substr(0,i)<<"\n";
                break;
            }
            cur = (cur->child)[s[i]-'a'];
        }
        if(cur->isword)
        {    
            cout<<"found "<<s.substr(0,i)<<"\n";
            cur->isword=false;
        }
        */
        
        //insert words in tree
        for(auto s:words)
            root = insert_trie(root , s);
            
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((root->child)[board[i][j]-'a'])     //char found in trie
                {   
                    string s = "" ;
                    s+=board[i][j];
                    //cout<<board[i][j]<<" ";
                    search_board(i,j,board,res, (root->child)[board[i][j]-'a'] ,s);
                    //cout<<"\n";
                }
            }
        }
        
        
        return res;
    }
};
