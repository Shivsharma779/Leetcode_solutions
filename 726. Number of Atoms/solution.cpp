class Solution {
public:
    void helper(int mul,int &i,map<string,int> &mp,string &s)
    {        
        while(i>=0)
        {
            
            //form current number 
            int cur_count = 0,pow=1;
            while(i>=0 and isdigit(s[i]))
            {
                cur_count += (s[i]-'0') * pow;
                i--, pow*=10;
            }
            
            //no digit before ele
            if(!cur_count)  cur_count = 1;          
            
            
            //opening brace, recurse
            if(i>=0 and s[i]==')')
            {
                i--;
                helper(mul*cur_count,i,mp,s);
            }
            //end recursion
            else if(i>=0 and s[i]=='(')
                return;
            //forming element name and store in map
            else
            {            
                string cur_ele = "";
                while(i>=0 and isalpha(s[i]))
                {
                    cur_ele = s[i] + cur_ele;
                    if(isupper(s[i]))
                        break;
                    i--;
                }
                
                //reverse(cur_ele.begin(),cur_ele.end());
                mp[cur_ele] += cur_count * mul;
            }
            i--;
        }   
    }
    
    string countOfAtoms(string s) {
        int mul=1,i=s.size()-1;
        map<string,int> mp;
        helper(mul,i,mp,s);
        
        string res="";
        for(auto x:mp)
        { 
            res += x.first;
            if(x.second!=1)
                res += to_string(x.second);
        }
        
        return res;
    }
};


    
