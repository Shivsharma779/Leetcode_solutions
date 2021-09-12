class NumArray {
public:
    vector<int> tree;
    int n;
    
    //////////////////////////////////////////////////////////////////////////////////////////
    void buildtree(vector<int>& nums , vector<int> &tree , int start,int end,int node)
    {
        if(start==end)
        {
            //cout<<start<<" "<<end<<" "<<node<<"\n";
            tree[node] = nums[start];
            return ;
        }
        
        
        int mid = (start + end)/2;
        //cout<<start<<" "<<end<<" "<<node<<" "<<mid<<"\n";
        buildtree(nums,tree,start,mid,node*2);
        buildtree(nums,tree,mid+1,end,node*2+1);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    NumArray(vector<int>& nums) {
        
        n=nums.size();     
        
        
        tree = vector<int>(4*n);
        
        buildtree(nums,tree,0,n-1,1);        
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////
    void updatetree(vector<int> &tree , int start,int end,int node,int &idx,int &val)
    {
        if(start==end)
        {
            tree[node]=val;
            return ;
        }
        
        int mid = (start + end)/2;
        if(idx<=mid)
            updatetree(tree,start,mid,node*2,idx,val);
        else
            updatetree(tree,mid+1,end,node*2+1,idx,val);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }   
    
    void update(int index, int val) {
        updatetree(tree,0,n-1,1,index,val);
        /*
        for(auto x:tree)
            cout<<x<<" ";
        cout<<"\n";
        */
    }
      
    //////////////////////////////////////////////////////////////////////////////////////////
    int rangeval(vector<int> &tree,int start,int end,int &left,int &right,int node)
    {
        //completely outside range
        if(right<start || end<left)
            return 0;
        
        //current node range completely inside given range
        if(start>=left && end<=right)
            return tree[node];
        
        //partially covers range
        int mid = (start + end)/2;
        int ans1 = rangeval(tree,start,mid,left,right,2*node);
        int ans2 = rangeval(tree,mid+1,end,left,right,2*node+1);
        return ans1+ans2;
        
    }
    
    int sumRange(int left, int right) {
        return rangeval(tree,0,n-1,left,right,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
