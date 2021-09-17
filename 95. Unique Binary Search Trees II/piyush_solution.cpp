class Solution {
public:
    
    //key-> l_r , value -> combination of all tree using range l to r
    unordered_map<string, vector<TreeNode*>> mp;
    vector<TreeNode*> helper(int l, int r)
    {
        if(l<=r)
        {
            vector<TreeNode*> ltree,rtree,res;      
            
            for(int i=l;i<=r;i++)
            {
                string key = to_string(l)+"_"+to_string(i-1);
                if(mp.find(key)!=mp.end())
                    ltree = mp[key];
                else
                    ltree = helper(l,i-1);
                
                key = to_string(i+1)+"_"+to_string(r);
                if(mp.find(key)!=mp.end())
                    rtree = mp[key];
                else
                    rtree = helper(i+1,r);
                
                
                //for all combinations of left and right subtree
                for(auto &lnode:ltree)
                {
                    for(auto &rnode:rtree)
                    {
                        TreeNode *root = new TreeNode(i,lnode,rnode);
                        res.push_back(root);
                    }
                }
            }
            
            
            mp[to_string(l) + "_" + to_string(r)] = res;
            return res;
        }
        return {0};
            
    }
    
 
    vector<TreeNode*> generateTrees(int n) {
        mp.clear();
        return helper(1,n);
    }
};
