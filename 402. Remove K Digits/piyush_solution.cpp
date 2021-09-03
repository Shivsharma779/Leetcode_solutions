class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.size()<=k)
            return "0";
        
        
        string res="";
 
        for(int i=0;i<s.size();i++)
        {
            while(k>0 and s[i]<res.back())
            {
                res.pop_back();
                k--;
            }
            
            res += s[i];
        }
        
        res = res.substr(0,res.size()-k);
        
        int i;
        for(i=0;i<s.size() and res[i]=='0';i++) ;
        
        res = res.substr(i);
        
        return res=="" ? "0" : res;
    }
};

/*
1342219

012

1
*/
