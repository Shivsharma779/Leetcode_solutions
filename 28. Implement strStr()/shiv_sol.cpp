class Solution {
public:
    int strStr(string &s , string &p) {
        int n = s.size() , m = p.size();
        if(n<m) return -1;
        
        for(int i = 0; i+m <= n ; i++){
            bool ans = true;
            for(int j = i, k =0 ; k<m ; j++,k++){
                if(s[j] != p[k]){
                    ans = false; break;
                }
            }
            
            
            if(ans) return i;
        }
        return -1;
    }
};
