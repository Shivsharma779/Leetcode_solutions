#define can_steal 1
#define cant_steal 0 

class Solution {
public:

    map <pair<TreeNode * , int>, int > m;
    int helper(TreeNode * root, int steal, int ans){
        if ( root == NULL ){
            return 0 ;
        }
        auto x = m.find({root,steal});
        if(x != m.end()) return x->second;
        int  with_steal = 0 , without_steal = 0 ;
        without_steal = helper(root->left,can_steal,ans) + helper(root->right,can_steal,ans);;
        
        
        if(steal){
            with_steal = root -> val + helper(root->left,cant_steal, ans) + helper(root->right,cant_steal, ans);
            
         
            
        }
        return m[{root,steal}] = max(with_steal,without_steal);
    }
    int rob(TreeNode* root) {

        return helper(root, can_steal, 0);
        
    }
};
