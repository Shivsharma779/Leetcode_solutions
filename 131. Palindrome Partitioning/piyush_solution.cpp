class Solution {
public:
    /*
    bool ispalindrome(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
    */
    
    void create_partitions(int start,string &s,vector<vector<string>> &res,vector<string> &temp, vector<vector<bool>> &dp)
    {
        if(start>=s.size()) 
            res.push_back(temp);
        else
        {
            for(int i=1; i<=(s.size() - start) ; i++)
            {
                string cur = s.substr(start,i);
                if(dp[start][start+i-1])
                {
                    temp.push_back(cur);
                    create_partitions(start+i,s,res,temp,dp);
                    temp.pop_back();
    }   }   }   }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        
        int n = s.size();
        vector<vector<bool>> dp( n, vector<bool>(n,false));
    	for(int i=0; i<n; i++) 
            dp[i][i] = true;

        for( int i=n-1; i >= 0; i-- )
    		for( int j=i+1; j < n; j++ )
		    	if( s[i] == s[j] && ( dp[i+1][j-1] || j-i <= 2 ) )
			    	dp[i][j] = true;
        
        
        create_partitions(0,s,res,temp,dp);
        return res;
    }
};
