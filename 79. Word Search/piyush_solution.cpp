class Solution {
public:
    bool issafe(vector<vector<char>>& a, int i,int j)
    {
        if(i>=0 && j>=0 && i<a.size() && j<a[0].size() && a[i][j]!='*')
            return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& a,string &word, int i, int j, int word_idx)
    {
        if(word[word_idx]==a[i][j])
        {
            if(word_idx==word.size()-1)
                return true;
            
            char c=a[i][j];
            a[i][j]='*';
            if(issafe(a,i+1,j)  && dfs(a,word,i+1,j,word_idx+1))
                return true;
            if(issafe(a,i-1,j)  && dfs(a,word,i-1,j,word_idx+1))
                return true;
            if(issafe(a,i,j+1)  && dfs(a,word,i,j+1,word_idx+1))
                return true;
            if(issafe(a,i,j-1)  && dfs(a,word,i,j-1,word_idx+1))
                return true;
            a[i][j]=c;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& a, string word) {
        int m=a.size(),n=a[0].size();     
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==word[0] && dfs(a,word,i,j,0))
                    return true;
        return false;                   
        
    }
};
