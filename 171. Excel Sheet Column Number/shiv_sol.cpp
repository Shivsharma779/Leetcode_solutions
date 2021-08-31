class Solution {
public:
    int titleToNumber(string &A) {
        int col = 0;
        for(auto &a : A){
            col = (col*26  - 'A') + a +1; 

        }
        return col;
    }
};
