class Solution {
public:
    
    void helper(TreeNode* root,vector<int> &res,int &maxlv,int lv)
    {
        if(root)
        {
            if(lv>maxlv)
            {
                maxlv=lv;
                res.push_back(root->val);
            }
            helper(root->right,res,maxlv,lv+1);
            helper(root->left,res,maxlv,lv+1);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> res;
        int maxlv=-1;
        helper(root,res,maxlv,0);
        return res;

        
        //below is using queue
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            res.push_back(q.front()->val);
            
            while(n--)
            {
                TreeNode* x = q.front();
                q.pop();
                if(x->right)
                    q.push(x->right); 
                if(x->left)
                    q.push(x->left);                               
            }
        }
        return res;
        
    }
};
