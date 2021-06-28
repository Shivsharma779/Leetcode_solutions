class Codec {
public:
    //https://www.youtube.com/watch?v=d81twp9YUzc
    void serial_helper(TreeNode* root , string &serial_tree)
    {
        if(root)
        {
            serial_tree += "," + to_string(root->val);
            serial_helper(root->left , serial_tree);
            serial_helper(root->right , serial_tree);           
        }
        else
            serial_tree += ",N";
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string serial_tree="";
        serial_helper(root , serial_tree);
        serial_tree = serial_tree.substr(1);         //remove first comma
        //cout<<serial_tree<<"\n";
        return serial_tree;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    
    vector<string> serial_to_vec(string &s)
    {
        string cur="";
        vector<string> v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==',')
            {
                v.push_back(cur);
                //cout<<cur<<" ";
                cur="";
            }
            else
                cur+=s[i];
        }
        //cout<<cur<<"\n";
        v.push_back(cur);           //append last entry of tree
        return v;
    }
    TreeNode* buildTree(vector<string> &tree_vec, int &i)
    {
        if(i>=tree_vec.size() || tree_vec[i]=="N" )
            return 0;
        else
        {
            TreeNode *temp = new TreeNode(stoi(tree_vec[i]));
            temp->left = buildTree(tree_vec,++i);
            temp->right = buildTree(tree_vec,++i);
            //cout<<temp->val<<"\n";
            return temp;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tree_vec = serial_to_vec(data);
        int i=0;
        return buildTree(tree_vec,i);
    }
};
