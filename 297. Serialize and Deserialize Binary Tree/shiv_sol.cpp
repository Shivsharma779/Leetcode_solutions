class Codec {
public:

    // Encodes a tree to a single string.
    
    void serial(TreeNode * root, stringstream &s){
        if(root){
            s << to_string(root->val) << " ";
            serial(root->left, s);
            serial(root->right, s);

        }
        else{
            s << "# ";
        }
    }
    string serialize(TreeNode* root) {
        stringstream ss;
        serial(root,ss);
        return ss.str();
    }
    
    TreeNode * deserial(stringstream &ss){
        string in;
        ss >> in;
        if(in == "#") return NULL;
        else{
            TreeNode * root = new TreeNode(stoi(in));
            root->left = deserial(ss);
            root->right = deserial(ss);
            return root;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserial(ss);
        
    }
};
