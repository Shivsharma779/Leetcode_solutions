class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        
        string previous, current = "";
        int num = 0;
        vector<int> no;
        vector<string> str;
        
        for( int i = 0 ; i < n ; i++ ){
            if(s[i] == '['){
               str.push_back(current) ;
               no.push_back(num);
                current = "";
                num = 0;
            }
            else if(s[i]  <= '9' && s[i] >= '0'){
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] == ']'){
                previous = str.back();
                str.pop_back();
                
                for(int i = 0 ; i < no.back(); i++) previous += current;
                no.pop_back();
                current = previous;
                
            }
            else current += s[i];
        }
        return current;
    }
};
