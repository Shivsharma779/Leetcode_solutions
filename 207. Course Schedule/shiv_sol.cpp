class Solution {
public:
    bool checkcycle(vector<vector<int>> &G , int i , vector<bool> &rec , vector<bool> &vis){
        bool ans = true;
        if(!vis[i]){
            vis[i] = true;
            rec[i] = true;
            
            for(auto a : G[i]){
                
                if(rec[a]) return false;
                else{
                    ans = checkcycle(G,a,rec,vis);
                    if(!ans) return ans;

                }
            }
            rec[i] = false;
        }
        return ans;
    }
    bool canFinish(int n, vector<vector<int>>& P) {
        vector<vector<int>> G(n);
        vector<bool> rec(n,false);
        vector<bool> vis(n,false);
        for(auto p: P){
            G[p[0]].push_back(p[1]);
        }
        
        bool ans = true;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                ans = checkcycle(G,i,rec,vis);
                if(!ans) return ans;
            }
        }
        return ans;
    }
};
