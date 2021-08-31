class Solution {
public:
    // https://www.youtube.com/watch?v=qe_pQCh09yU
    void buildgraph(vector<vector<int>> &graph , vector<vector<int>>& prerequisites)
    {
        for(auto edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);      //prereq -> course   
            //cout<<edge[1]<<"->"<<edge[0]<<"\n";
        }      
    }
    /////////////////////////////////////////////////////////////////////////////////
    bool cyclic_helper(vector<short> &visit , vector<vector<int>> &graph , int node)
    {
        //cout<<node<<" ";
        if(visit[node] == 1)        //node in current stack so cycle formed
            return true;
        
        if(visit[node] == 2)        //node visited and processed
            return false;
        
        visit[node] = 1;
        
        for(auto neighbour : graph[node])
            if(cyclic_helper(visit , graph , neighbour))
                return true;
        
        visit[node] = 2;
        return false;
    }
    
    bool cyclic( vector<vector<int>> &graph , int node)
    {
        vector<short> visit(graph.size() , 0);
        
        for(int i=0;i<visit.size();i++)
            if(!visit[i] && cyclic_helper(visit , graph , i))
                return true;
        return false;                         
    }
    /////////////////////////////////////////////////////////////////////////////////
    void topological_sort(vector<bool> &visit , vector<vector<int>> &graph , int node , vector<int> &res)
    {
        //cout<<node<<" ";
        visit[node]=true;
        
        for(auto neighbor : graph[node])
            if(!visit[neighbor])
                topological_sort(visit , graph , neighbor , res);
        
        res.push_back(node);
    }
    /////////////////////////////////////////////////////////////////////////////////
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        int n = prerequisites.size();
        
        vector<vector<int>> graph(numCourses);
        buildgraph(graph , prerequisites);
        
        if(cyclic(graph, 0))
            return res;
        
        vector<bool> visit(numCourses , false);
        
        for(int i=0;i<numCourses ; i++)
            if(!visit[i])
                topological_sort(visit , graph , i , res);
        
        reverse(res.begin() , res.end());
        return res;
    }
};
