class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        
        while(root)        
        {
            st.push(root);
            root=root->left;
        }    
        
        vector<int> res;
        
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            
            res.push_back(temp->val);
            temp = temp->right;
            
            while(temp)
            {
                st.push(temp);
                temp = temp->left;
            }    
        }
        
        return res;
    }
};
