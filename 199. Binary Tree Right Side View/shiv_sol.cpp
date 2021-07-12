class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> ans;
        queue<TreeNode *> q;
        
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                root = q.front();
                if (root -> left)  q.push(root->left);
                if (root -> right) q.push(root->right);
                q.pop();
            }
            ans.push_back(root->val);
            
        }
       
        return ans;
    }
};
