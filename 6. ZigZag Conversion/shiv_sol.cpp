class Solution {
public:
    string convert(string s, int numRows) {
        
        
       if(numRows == 1) return s;
        string ans;
        
        
        for(int i  = 0; i < numRows; i++){
            bool f = true;
            for(int j = i; j < s.size(); ){
                ans.push_back(s[j]);
                if(i == 0 || i == numRows - 1) j+=2*(numRows-1);
                else if(f) j += 2*(numRows-1-i), f = false;
                else j+=2*i,f=true;
            }
        }
        return ans;
    }
};
