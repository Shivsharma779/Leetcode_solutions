class Solution {
public:
    //https://leetcode.com/problems/string-to-integer-atoi/discuss/4654/My-simple-solution
    ///////////////////////////////////////////////////////////////////////////////////
    int m1_using_longlong(string &s)
    {
        int i=0,n=s.size(),j=0;
        long long res=0;
        
        //ignore spaces
        while(i<n && s[i]==' ')
            i++;
        
        //chk negative
        bool neg=false;
        if(i<n && s[i]=='-')
        {
            neg=true;
            i++;
        }
        //ignore + sign
        else if(i<n && s[i]=='+')
            i++;
        
        j=i;
        //count all numeric characters
        while(j<n && s[j]>='0' && s[j]<='9')
            j++;
        
        //remove leading zeros
        while(i<n && s[i]=='0')
            i++;
        
        string snum;
        //no numeric characters
        if(j-i == 0)    return res;
        //save numeric substring
        else
            snum = s.substr(i,(j-i));
        
        //cout<<snum<<"\n";
        
        
        //evaluate string number and store to long long int
        res=0;
        for(int k=0; k < snum.size(); k++)
        {
            res *= 10;
            res += (snum[k]-'0');
            //cout<<res<<"\n";
            if(res>INT_MAX)     //break if res is overflowed
                break;
        }
        

        //evaluate according to sign
        if(neg)
        {
            res = -res;     //negate
            res = (res<INT_MIN) ? INT_MIN : res;
        }
        else
            res = (res>INT_MAX) ? INT_MAX : res;
        
        return res;
    }
    ///////////////////////////////////////////////////////////////////////////////////
    int m2_no_longlong(string &s)
    {
        int i=0,n=s.size(),base=0;
        bool neg=false;
        
        while(i<n && s[i]==' ')     //remove leading spaces
            i++;
        
        if(i<n && s[i]=='-')        //chk negative
        {
            neg=true;
            i++;
        }
        else if(i<n && s[i]=='+')   //ignore + sign
            i++;
        
        while(i<n && s[i]>='0' && s[i]<='9')
        {
            //we check beforehand if next digit wil overflow the int range
            if(base > INT_MAX/10  || ((base==INT_MAX/10) && (s[i]-'0' > INT_MAX%10)))
                return neg ? INT_MIN : INT_MAX;
            
            //
            base = base*10 + (s[i]-'0');
            i++;
        }
        
        return neg ? -1*base : base;
    }
    ///////////////////////////////////////////////////////////////////////////////////
    int myAtoi(string s) {
        //return m1_using_longlong(s);
        return m2_no_longlong(s);
        
    }
};
