/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> a;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return  a;
    }
};
