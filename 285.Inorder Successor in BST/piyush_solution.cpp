class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void helper(Node *root , int &val,Node *(&res))
    {
        if(root)
        {
            if((root->data > val)  &&  (res==0   ||   (root->data < res->data)))
            {
                //cout<<root->data<<"\n";
                res = root;
                helper(root->left , val , res);
            }
            else
                helper(root->right , val , res);
        }
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *res = NULL;
        helper(root , x->data , res);
        //cout<<res->data<<"\n";
        return res;
    }
};
