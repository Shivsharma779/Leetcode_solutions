class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode * head = new TreeNode;
        if(t1 != NULL){
            head->val = t1->val;
        }
        if(t2 != NULL){
            head->val += t2->val;
        }
        if(t1 == NULL && t2 == NULL) return NULL;
        // cout << head->val;
        
        TreeNode* leftst = NULL;
        TreeNode* rightst = NULL;
        TreeNode* litr1 , *litr2, *ritr1,*ritr2;
        litr1=litr2=ritr1=ritr2=NULL;
        if(t1 != NULL && t1->left  != NULL)litr1 = t1->left;
        if(t2 != NULL && t2->left  != NULL)litr2 = t2->left;
        if(t1 != NULL && t1->right != NULL)ritr1 = t1->right;
        if(t2 != NULL && t2->right != NULL)ritr2 = t2->right;
        leftst =mergeTrees(litr1,litr2);
        rightst=mergeTrees(ritr1,ritr2);
        
        head->left= leftst;
        head->right= rightst;
        
        return head;
    }
};
