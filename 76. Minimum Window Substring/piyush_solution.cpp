class Solution {
    //https://www.youtube.com/watch?v=0GOyCIJ2ajQ
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);    //128 ASCII characters
        for(auto c:t)
            freq[c]++;
        
        int l=0,cur=0,minl=INT_MAX;
        string res="";
        
        for(int r=0;r<s.size();r++)
        {
            freq[s[r]]--;
            if(freq[s[r]] >= 0)     //this is a required character
                cur++;
            
            while(cur == t.size())  //start shrinking window till valid
            {
                if(minl > r-l+1)    //save min length
                {
                    minl = r-l+1;
                    res = s.substr(l , r-l+1);
                }
                
                freq[s[l]]++;
                
                if(freq[s[l]] > 0)      //required char removed
                    cur--;
                
                l++;
            }
        }
        
        return res;
        
    }
};
