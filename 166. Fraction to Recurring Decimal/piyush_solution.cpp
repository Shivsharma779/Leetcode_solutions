class Solution {
public:
    //https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51160/C%2B%2B-unordered_map
    string fractionToDecimal(int num, int den) {

        unordered_map<int,int> mp;
        string res=""  , decimals = "";
        
        if(num==0)
            return "0";
        
        if(num<0 ^ den<0)   //negative nums
            res+='-';
        num = abs(num);
        den = abs(den);
        
        long div = num/den , rem = num%den;     //long to handle overflow
        res += to_string(div);
        
        if(rem==0)      //no decimal values
            return res;
        
        res += '.';
        
        while(rem)
        {
            if(mp.find(rem)!=mp.end())
            {
                res.insert(mp[rem],"(");
                return res + ')';
            }
            //cout<<res<<"\n";
            
            mp[rem] = res.size();
            rem*=10;
            div = rem/den;
            rem = rem%den;
            res += to_string(div);

            
        }
        
        return res ;
    
    }
};
