class Solution {
public:
    int helper(string &s, int &i){
        if(i == s.size()) return 0;
        int ans = 0;
        int curr = 0;
        char op = '+';
        while(i < s.size()){
            if(s[i] == ' ');
            else if(s[i] == '('){
                i++;
                curr =  helper(s,i);
            }
            
            else if(isdigit(s[i])){
                curr = curr *10 + (s[i]- '0');
            }
            
            else if(s[i] == '+' || s[i] == '-'){
                if(op == '+') ans += curr;
                else ans -= curr;
                
                curr = 0;
                op = s[i];
               
            }
            else if(s[i] == ')'){
                break;
            } 
            else{
                cout << "edge case " << s[i] << endl;
            }
            
            i++;
            
        }
        
        if(op == '+') ans += curr;
        else ans -= curr;
        return ans;
    }
    int calculate(string s) {
        int i = 0;
        return helper(s,i);
    }
};
