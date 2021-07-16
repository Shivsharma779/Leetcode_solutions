class Solution {
public:
    void moveZeroes(vector<int>& no) {
        int n = no.size();
        
        
        for(int i = 0, j = 0; i  < n; i++){
            if(no[i] != 0) swap(no[j++],no[i]);    
        } 
        
    
    }
};
