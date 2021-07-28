class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root)
            return res;
        
        queue<TreeNode*> st;
        int i=0;
        st.push(root);
        
            
        while(!st.empty())
        {
            int n=st.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* x = st.front();
                temp.push_back(x->val);
                if(x->left)
                    st.push(x->left);
                if(x->right)
                    st.push(x->right);
                    
                st.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};
