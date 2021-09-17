class Solution {
public:
       
    int helper(string &s, int &i)
    {
        if(i==s.size())
            return 0;
        
        int csign=1,num=0,cur=0;
        
        for(;i<s.size();i++)
        {
            //ignore spaces
            if(s[i]==' ')    
                continue;
            //recurse to solve subexpression
            else if(s[i]=='(')
            {
                i++;
                cur += csign * helper(s,i);
            }
            //solved current subexpr
            else if(s[i]==')')
                break;
            else if(s[i]=='-')
            {
                cur += csign * num;
                //reset number
                num = 0;
                
                csign = -1;
            }
            else if(s[i]=='+')
            {
                cur += csign * num;
                ///reset number
                num = 0;
                
                csign = 1;
            }
            //apend digit to number
            else
                num = num*10 + (s[i]-'0');
        }
        
        //evaluate last seen number
        cur += csign * num;
        return cur;
    }
    
    int calculate(string s) {
        int i=0;
        return helper(s,i);
    }
};

