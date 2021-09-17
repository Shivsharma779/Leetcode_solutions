class Solution {
public:
    map<pair<int,int>,vector<TreeNode *> > dp;
    vector<TreeNode *> trees(int s, int e){
        if(s > e){
            dp[{s,e}] = {NULL};
            return {NULL};
        }
        
        vector<TreeNode * > ans;
        for(int i = s; i <=e ;i++){
            vector<TreeNode * > l , r;
            
            if(dp.find({i+1,e}) == dp.end() ) r  = trees (i+1,e);
            else r = dp[{i+1,e}];
            
            if(dp.find({s,i-1}) == dp.end() )l = trees(s,i-1);
            else l = dp[{s,i-1}];
            
            for(auto lst : l){
                for(auto rst: r){
                    TreeNode * root = new TreeNode(i,lst,rst);
                    
                    ans.push_back(root);
                }
            }
            
        }
        dp[{s,e}] = ans;
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return trees(1,n);
    }
};
