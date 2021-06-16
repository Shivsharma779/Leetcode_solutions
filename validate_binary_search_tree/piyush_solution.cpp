long prev = LLONG_MIN;
    
bool isValidBST(TreeNode* root) {
    if(root)
    {
        if(!isValidBST(root ->left))
            return false;
        if(prev >= root ->val)
            return false;

        prev = root ->val;

        if(!isValidBST(root ->right))
            return false;
    }
    return true;
}
