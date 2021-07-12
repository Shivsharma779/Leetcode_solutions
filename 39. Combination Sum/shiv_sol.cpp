class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> &C, int target, int i, vector<int> &c, int cs){
        if(cs > target) return;
        if(i == -1){
            return;
        } 
     
        c.push_back(C[i]);
        cs+= C[i];
        
        if(cs == target) {ans.push_back(c); }
        helper(C,target,i,c,cs);
        
        c.pop_back();
        cs-=C[i];
        helper(C,target,i-1,c,cs);
        
    }
    vector<vector<int>> combinationSum(vector<int>& C, int target) {
        vector<int> c;
        helper(C,target,C.size()-1,c,0);
        return ans;
    }
};
