class Solution {
    TreeNode* prev = 0;
public:
    void flatten(TreeNode* root) {
        if(root)
        {
            flatten(root->right);
            flatten(root->left);
            
            root->right=prev;
            root->left=0;
            prev=root;
        }
    }
};
