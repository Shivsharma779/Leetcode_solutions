class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& E) {
        
        vector<vector<int>> adj(n);
        for(auto e: E)  adj[e[1]].push_back(e[0]);
        
        vector<int> ind(n);
        for(auto from : adj)   for(auto to : from) ind[to]++;
        
        queue<int> q;
        for(int i = 0; i < n ; i++){
            if(!ind[i]) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int from = q.front(); q.pop();
            ans.push_back(from);
            
            for(auto to: adj[from]){
                if(!(--ind[to])) q.push(to);
            }
        }
        
        if(ans.size() == n) return ans;
        else return {};
                   
        
        
        
        
    }
};
