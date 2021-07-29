class Solution {
public:
    TreeNode * makeTree(vector<int> &A , int l , int r){
        if(l<=r){
            TreeNode * root = NULL;
            int mid = (l+r)/2;
            root = new TreeNode(A[mid]);
            if(l<= mid-1) root->left = makeTree(A,l,mid-1);
            if(mid+1 <= r) root->right = makeTree(A,mid+1,r);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& A) {
        int n = A.size();
        int l = 0 , r = n-1;
        
        return makeTree(A,l,r);
    }
};
