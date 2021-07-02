class Solution {
public:
    void sortColors(vector<int>& A) {
        
        int z = 0, l =0 , r = A.size()-1;
        while( l <= r){
            if(A[l] == 0) swap(A[l++],A[z++]);
            else if (A[l] == 2) swap(A[l],A[r--]);
            else l++;
            
        }
        
    }
};
