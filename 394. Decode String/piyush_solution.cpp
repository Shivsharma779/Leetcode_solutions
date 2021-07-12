class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto c:s)
        {
            if(c==']')
            {
                string repstr="";
                while(!st.empty() && st.top()!="[")
                {
                    repstr=st.top() + repstr;
                    st.pop();
                }
                st.pop();       //pop '['
                if(!st.empty())
                {
                    string countstr="";
                    while(!st.empty() && (st.top()>="0" && st.top()<="9" ))
                    {
                        countstr=st.top()+countstr;
                        st.pop();
                    }
                    int countrep=stoi(countstr);
                    string repeat=repstr;
                    repstr="";
                    while(countrep--)
                        repstr+=repeat;
                }
                
                st.push(repstr);
            }
            else
            {
                string p(1, c);
                st.push(p);
            }
        }
        
        string res="";
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res;
        
        
    }
};
