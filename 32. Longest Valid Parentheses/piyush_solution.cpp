class Solution {
    //https://www.youtube.com/watch?v=VdQuwtEd10M
public:
    
    int approach1(string s)         //O(N) time , O(N) space
    {
        stack<int> st;
        int maxl = 0;
        st.push(-1);
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')       
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    maxl = max(maxl , i - st.top());      //valid_len = cur_idx - top_idx              
            }
        }
        
        return maxl;
    }
    
    int approach2(string s)         //O(N) time , O(1) space
    {
        int maxl = 0,open = 0 , close=0;
        
        //fwd pass
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open==close)
                maxl = max(maxl , open+close);
            else if(open<close )    //invalid string
                open=close=0;
        }
        
        open=close=0;
        //backward pass         
        for(int i=s.size()-1 ;i>=0;i--)
        {
            if(s[i]==')')       //in reverse this will be opening bracket
                open++;
            else
                close++;
            
            if(open==close)
                maxl = max(maxl , open+close);
            else if(open<close)    //invlaid string
                open=close=0;
        }
        
        return maxl;
    }
    int longestValidParentheses(string s) {
        //return approach1(s);
        return approach2(s);

    }
};
