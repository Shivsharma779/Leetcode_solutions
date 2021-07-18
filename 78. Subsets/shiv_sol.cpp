class Solution {
public:
    vector<vector<int>> ans;
    void gen_sub(vector<int> &no, vector<int> curr,  int i){
        
        int n = no.size();
        if( i == n ) {ans.push_back(curr); return;}
        
        
        gen_sub(no,curr,i+1);
        curr.push_back(no[i]);
        gen_sub(no,curr,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& no) {
        vector<int> x;
        gen_sub(no,x,0);
        return ans;
        
        
    }
};
