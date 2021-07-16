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
    
    void util(TreeNode* root, int &k,int &ksmall)
    {
        if(root && k)
        {
            util(root->left,k,ksmall);
            k--;
            if(k==0)
            {
                ksmall=root->val;
                return ;
            }
            util(root->right,k,ksmall);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ksmall;
        util(root,k,ksmall);
        return ksmall;
    }
};
