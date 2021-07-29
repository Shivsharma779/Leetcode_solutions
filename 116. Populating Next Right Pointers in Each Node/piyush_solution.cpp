class Solution {
public:
    //use the next pointer to set next pointer values at lower level
     Node* connect(Node* root) {
        
        if(root)
        {
            if(root->left)
                root->left->next = root->right;
            if(root->right)
                root->right->next = (root->next) ? (root->next->left) : NULL;
            
            connect(root->left);
            connect(root->right);
        }
        return root;
        
    }
};
