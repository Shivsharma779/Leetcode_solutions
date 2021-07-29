/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        deque<TreeNode *> q;
        
        if(root)q.push_back(root);
        bool right = true;
        while(!q.empty()){
            int x = q.size();
            vector<int> curr;
            while(x--){
                TreeNode * n = (right)?q.front():q.back();
                curr.push_back(n->val);
                if(right){
                    if(n->left) q.push_back(n->left);
                    if(n->right) q.push_back(n->right);
                }
                else{
                    if(n->right) q.push_front(n->right);
                    if(n->left) q.push_front(n->left);
                }
                
                if(right)q.pop_front();
                else q.pop_back();
                
            }
            ans.push_back(curr);
            right = !right;
        }
        return ans;
    }
};
