class Solution {
public:
    string convert(string &s)
    {
        int count=1;
        char num=s[0];      //string atleast size 1
        string res="";
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])    //count repeating digits
                count++;
            else
            {
                res += to_string(count) + num;  //count and say
                num=s[i];       //new number to count
                count=1;        //reset counter
            }
        }
        res += to_string(count) + num;      //append last digit count and say
        
        return res;
    }
    
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++)
            res = convert(res);
            
        return  res;
    }
};
