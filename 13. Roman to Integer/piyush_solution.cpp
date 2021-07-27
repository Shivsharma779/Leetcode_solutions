class Solution {
public:
    int romanToInt(string s) {
        int res=0,cur,prev;
        unordered_map<char,short> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        res = mp[s[0]];
        for(int i=1;i<s.size();i++)
        {
            cur = mp[s[i]];
            prev = mp[s[i-1]];
            if(cur<=prev)
                res += cur;
            else
                res += cur - prev*2;    
            /*
            subtract twice because in previous iteration it that would have been added.
            IV
            res = 1
            res = 6 - 2*1
            */
        }
        return res;
    }
};
