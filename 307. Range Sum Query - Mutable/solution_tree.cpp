#define ll long long

class treenode{
    public:
    treenode *left, *right;
    ll l,r,val;

    treenode(){
        val = 0;
    }
    
    treenode(int a,int i,int j){
        val = a,l=i,r=j;
    }
};

class NumArray {
public:
    
      
    treenode *root; 
    /////////////////////////////////////////////////////////////////////////
    treenode * buildtree(int l,int r,vector<int>& nums){
        if(l==r){
            treenode *cur = new treenode(nums[l],l,r);
            return cur;
        }
        else
        {
            treenode *cur = new treenode();
            
            int mid = (l+r)/2;
            cur->left = buildtree(l,mid,nums);
            cur->right = buildtree(mid+1,r,nums);
            cur->val = cur->left->val + cur->right->val;
            
            cur->l = l;
            cur->r = r;
            
            return cur;
        }
        return 0;
    }
    
    NumArray(vector<int>& nums) {
        root = buildtree(0,nums.size()-1,nums);
    }
    /////////////////////////////////////////////////////////////////////////
    int updatetree(int i,int &val,treenode *root)
    {
        if(root->l==root->r and root->l==i)
        {
            root->val = val;
            return root->val;
        }
        
        int mid = (root->l + root->r)/2;
        int lres=root->left->val, rres=root->right->val;
        
        if(i<=mid)
            lres = updatetree(i,val,root->left);  
        else
            rres = updatetree(i,val,root->right);
        
        root->val = rres + lres;
        
        //cout<<root->l<<" "<<root->r<<" "<<root->val<<endl;
        
        return root->val;
    }
    void update(int index, int val) {
        updatetree(index,val,root);
    }
    
    /////////////////////////////////////////////////////////////////////////
    
    int sumtree(int l, int r,treenode *root)
    {
        //cout<<l <<" "<<r<<endl;
        if(l>r) return 0;
        
        //exact range
        if(l==(root->l) and r==(root->r))
            return root->val;
        
        
        int mid = (root->l + root->r)/2;
        
        return  sumtree(l,min(r,mid),root->left) + 
                sumtree(max(l,mid+1),r,root->right);
    }
    
    int sumRange(int left, int right) {
        return sumtree(left,right,root);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
