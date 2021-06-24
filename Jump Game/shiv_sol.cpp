class Solution {
public:
    bool canJump(vector<int>& A) {
        int n = A.size();
        int last = n-1;
        for(int i = n-2; i > -1 ; i--){
            if(i + A[i] >= last) last = i; 
            
        }
        return (last == 0);
        
    }
};
