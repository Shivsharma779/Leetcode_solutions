class Solution {
public:
    bool isValid(string s) {
        int p1=0,p2=0,p3=0,i;
        int n=s.length();
        
        stack <char> st;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(st.size()==0)               //stack empty during string parsing
                return false; 
            else if(st.top()=='(' && s[i]== ')' ||
                    st.top()=='[' && s[i]== ']' ||
                    st.top()=='{' && s[i]== '}' )
                st.pop();
            else
                return false;
        }
        
        return (st.empty());
       
    }
};
