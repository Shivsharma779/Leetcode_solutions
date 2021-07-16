class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i =0 ; i<n ; i++){
            
            for(int j =i, k = i; j > -1 && k < n && s[j] == s[k]; j--, k++)ans++;
            for(int j =i, k = 1+i; j > -1 && k < n && s[j] == s[k]; j--, k++)ans++;
                
             
            
        }  
        return ans;
    }
};
