class Solution {
public:
    
    double bfs(vector<string> query,unordered_map<string,vector<pair<string,double>>> &adj)
    {
        unordered_set<string> vis;
        queue<pair<string,double>> q;
        double ans=1.0;
        
        q.push({query[0],1.0});
        
        while(!q.empty())
        {
            string var = q.front().first;
            double curans = q.front().second;
            q.pop();
            
            if(var==query[1])
                return curans;
            
            vis.insert(var);
            
            for(auto &neigh:adj[var])
            {
                if(vis.find(neigh.first) == vis.end())
                {
                    q.push({neigh.first , curans * neigh.second});
                }
            }
        }
        
        return -1.0;
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equ, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        
        for(int i=0;i<equ.size();i++)
        {
            adj[equ[i][0]].push_back( {equ[i][1], values[i]} );
            adj[equ[i][1]].push_back( {equ[i][0], 1.0/values[i]} );
        }
        
        vector<double> res;
        
        for(auto q:queries)
        {
            if(adj.find(q[0])==adj.end() or adj.find(q[1])==adj.end())
                res.push_back(double(-1));
            else
            {
                res.push_back( bfs(q,adj) );
                
            }
        }
        return res;
    }
};

/*
a/b b/c c/d

a/d
*/
