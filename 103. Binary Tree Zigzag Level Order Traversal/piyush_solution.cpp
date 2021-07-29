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
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        
        if(!root)
            return res;
        bool rev=0;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* cur=q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(rev)
                reverse(temp.begin(),temp.end());
            res.push_back(temp);
            rev^=1;
        }
        return res;
    }
};
