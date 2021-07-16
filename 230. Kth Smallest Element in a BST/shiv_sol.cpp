class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inot;
        inorder(root,inot);
        return inot[k-1];
        
    }
    void inorder(TreeNode* root,vector<int> &inot){
        if(root == NULL) return;
        inorder(root->left,inot);
        inot.push_back(root->val);
        inorder(root->right,inot);
        
        
    }
};
