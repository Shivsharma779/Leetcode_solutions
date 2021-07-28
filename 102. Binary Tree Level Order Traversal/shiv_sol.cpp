class Solution {
public:
    vector<vector<int>> ans;
    void helper(TreeNode *root, int depth){
        if ( root == NULL ){
            return;
        }
        if (depth == ans.size()){
            ans.push_back(vector<int>());
        }
        
        ans[depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};
