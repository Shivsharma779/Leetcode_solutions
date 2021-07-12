//space , time : O(N) , O(N)
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int st , int ed , int &i , unordered_map<int,int> &mp)
    {
        if(i<preorder.size() and st<=ed)
        {
            TreeNode *temp = new TreeNode(preorder[i]);
            int j = mp[preorder[i]];
            
            i++;
            
            temp->left = helper(preorder , inorder , st , j - 1 , i, mp);
            temp->right = helper(preorder , inorder , j+1 , ed , i, mp);
            return temp;
        }
        return 0;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int i=0;
        return helper(preorder , inorder , 0 , inorder.size() - 1 , i , mp);
    }
};
