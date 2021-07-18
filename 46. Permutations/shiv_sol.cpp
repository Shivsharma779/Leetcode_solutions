class Solution {
public:
    
    vector<vector<int>> solve(vector<vector<int>> &s, int &n){
        vector<vector<int>> ans; 
        for(auto seq : s){
            for(int i = 0; i <= seq.size(); i++){
                vector<int> c(seq.begin(),seq.begin()+i);
                c.push_back(n);
                for(int j = i ; j < seq.size(); j++ ) c.push_back(seq[j]);
                ans.push_back(c);
            }
        }
        // for(auto a: ans) {for (auto b : a) cout << b; cout <<"\n";}
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans{{nums[0]}};
        for(int i = 1 ; i < nums.size() ;i++){
           
            ans = solve(ans,nums[i]);
            
        }
        
        return ans; 
            
    }   
};
