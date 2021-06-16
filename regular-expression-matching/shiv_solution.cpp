class Solution {
public:
    bool helper(int i , int j, string &s , string &p){
        // cout << i << " " << j << endl;

        int n = s.size() , m = p.size();
        while(i > -1 && j > -1 && (s[i] == p[j] || p[j] == '.')) i--,j--;
        // cout << i << " " << j << endl;
        
        if(j > -1 && p[j] == '*'){
            j--;
            int temp = i;
            while(i > -1 && (s[i] == p[j] || p[j] == '.')) i--;
            j--;
            
            for(int k = i ; k <= temp; k++){
                if(helper(k,j,s,p)) return true;
            }
        }
        if(i == -1 && j == -1) return true;
        
        
        return false;
        
        
    }
    bool isMatch(string &s, string &p) {
        int n = s.size() , m = p.size() ; 
        return helper(n-1,m-1,s,p);
        
    }
};
