class Solution {
public:
    
    bool cyclic(vector<int> adj[],int i,int visit[])
    {
        if(visit[i]==1)            return true;
        if(visit[i]==2)            return false;
        
        visit[i]=1;
        for(auto x:adj[i])
            if(cyclic(adj,x,visit))  //not processed and cycle detected
                return true;
        visit[i]=2;
        
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& prereq) {
        
        //0 univisted
        //1 processing
        //2 processed
        
        int visit[v];
        memset(visit,0,sizeof(visit));
        vector<int> adj[v];
        
        for(auto edge:prereq)               //build adj list
            adj[edge[0]].push_back(edge[1]);
        
        for(int i=0;i<v;i++)
            if(visit[i]==0 && cyclic(adj,i,visit))
                return false;
        
        return true;
    }
};
