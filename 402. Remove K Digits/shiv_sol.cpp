class Solution {
public:
    string removeKdigits(string s, int k) {
       
        
        string ans = "0";
        for(int i = 0 ; i <= k; i++){
            int m = s.size();
            int j;
            // removing leading 0
            for(j = 0 ; j < m ; j++){
                if(s[j]!='0') break;
            }
            
            s = s.substr(j,-1);
            
            if(i != k)
            {
                for( j = 0 ; j < m-1 ; j++){
                if(s[j] > s[j+1]) break;
                }
                s.erase(j,1);
            }
            
        }
        
        
        return (s.empty()) ? "0" : s;
    }
};

// 1432219
