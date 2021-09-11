
class Solution{
  public:
  
    Node *res;
    void helper(Node *root, Node *x)
    {
        if(root==x)
        {
            if(root->right)
            {
                Node* temp=root->right;
                while(temp->left)
                    temp = temp->left;
                res = temp;
            }
            
        }
        else if(root->data < x->data)
        {
            helper(root->right,x);
            
        }
        else
        {
            helper(root->left,x);
            if(res==0)
                res=root;
        }
        
    }
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        res=0;
        helper(root,x);
        return res;
    }
};
