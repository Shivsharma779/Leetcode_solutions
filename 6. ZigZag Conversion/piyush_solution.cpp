class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> a(numRows,"");
        for(int i=0;i<s.size();)
        {
            for(int c=0;c<numRows and i<s.size(); c++,i++)
                a[c] += s[i];
            
            for(int c=numRows-2;c>0 and i<s.size(); c--,i++)
                a[c] += s[i];
        }
        
        string res="";
        for(auto &x:a)
            res+=x;
        return res;
    }
};
