    bool isValid(string s) {
        vector<char> st;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') st.push_back(c);
            else{
                if(c == '}'){
                    if(st.empty() || st.back() != '{') return false;
                    st.pop_back();
                }
                if(c == ')'){
                    if(st.empty() || st.back() != '(') return false;
                    st.pop_back();
                }
                if(c == ']'){
                    if(st.empty() || st.back() != '[') return false;
                    st.pop_back();
                }
                // else return false;
            }
        }
        // for(auto c : st) cout << c << " ";/
        // cout << endl << st.size() << endl;
        if(!st.empty()) return false;
        return true;
    }
