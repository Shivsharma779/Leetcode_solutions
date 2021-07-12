class Solution {
public:
    TreeNode * helper(vector<int> &pr, vector<int> &in, int ps, int pe, int is,int ie ){
        
        if(pe < ps) return NULL;
        
        int bp;
        for(int i = is; is <= ie; i++){
            if(pr[ps] == in[i]) {bp = i; break;}
            
        }
        
        TreeNode * left  = helper(pr,in,ps+1,ps+bp-is,is,bp-1);
        TreeNode * right = helper(pr,in,ps+bp-is+1,pe,bp+1,ie);
        return new TreeNode(pr[ps],left,right);
        
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        int n = pr.size();
        return helper(pr,in,0,n-1,0,n-1);
    }
};
