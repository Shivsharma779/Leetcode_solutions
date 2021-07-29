class Solution {
public:
    Node* connect(Node* root) {
        
        if(root && root->left){
            connect(root->left);
            connect(root->right);
            Node * lr = root->left , *rl = root->right;
            
            while(lr) 
                lr->next = rl,lr = lr->right, rl = rl->left;
            
            
        }
        return root;
        
    }
};
