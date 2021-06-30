class Solution {
public:
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if(m.size() == 0 || m[0].size() == 0) return false;
        
          int r=matrix.size();
        if(r==0)
            return false;
        int c=matrix[0].size();
        int row=0, col=c-1;
        while(row<r && col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                ++row;
            else
                --col;
        }
    return false;
        
        
    }
};
