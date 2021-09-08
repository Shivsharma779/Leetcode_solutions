void helper(vector<int> adj[], bool visit[], int node, string &res)
{
    visit[node]=true;
    
    for(auto neigh:adj[node])
        if(!visit[neigh])
            helper(adj,visit,neigh,res);
            
    res.push_back('a' + node);
}

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        string res="";
        vector<int> adj[k];

        for(int i=0;i<n-1;i++)
        {
            string cur=dict[i], next=dict[i+1];
            
            for(int j=0;j<cur.size() and j<next.size();j++)
            {
                if(cur[j] != next[j])
                {
                    adj[cur[j]-'a'].push_back(next[j]-'a');
                    break;
                }
            }
        }

        bool visit[k]={};
        
        for (int i = 0; i < k; i++)
            if (visit[i] == false)
                helper(adj,visit,i,res);
                
        reverse(res.begin(),res.end());
        return res;
        
    }
};

/*

b d a c


a:2
b:0
c:3
d:1

a b c

a:1
b:2
c:0



*/
