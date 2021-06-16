class Solution {    
public:
    bool helper(TreeNode* root, long root_min , long root_max){
        if (root == NULL)
            return true;
        bool result;
        if(root->val >= root_max || root->val <= root_min) return false;
        result = helper(root->left,root_min,root->val);
        result = result && helper(root->right,root->val,root_max);
        

        return result;
        
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
