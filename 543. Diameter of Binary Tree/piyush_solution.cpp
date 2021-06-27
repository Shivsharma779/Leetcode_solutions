class Solution {
    
    int maxdia(TreeNode* root,int depth,int &maxd)
    {
        if(root)
        {
            int ld=maxdia(root->left,depth+1,maxd);
            int rd=maxdia(root->right,depth+1,maxd);
            
            maxd=max(maxd,ld+rd);
            return max(ld,rd)+1;
        }
        return 0;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd=0;
        maxdia(root,0,maxd);
        return maxd;
        
        
    }
};
