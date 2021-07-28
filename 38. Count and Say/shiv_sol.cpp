string countAndSay(int n) {
        if (n == 1) return "1";
        else if(n==2) return "11";
        else{
            string ans;
            string s = countAndSay(n-1);
            int c = 1;
            
            for(int i = 0; i < s.size(); i++){
                if(i < s.size()-1 && s[i+1] == s[i]) c++;
                else{
                    
                    ans.push_back(c+'0');
                    ans.push_back(s[i]);
                    c = 1;
                }
            }
            return ans;
        }
        
    }
