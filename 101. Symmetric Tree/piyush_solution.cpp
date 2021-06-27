class Solution {
public:
    bool helper(TreeNode* root1 , TreeNode* root2)
    {
        if(root1 && root2)
        {
            if(root1->val==root2->val &&
              helper(root1->left,root2->right) && helper(root1->right,root2->left))
                return true;
        }
        else if(!root1 && !root2)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
};
