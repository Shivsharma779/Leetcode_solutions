class Solution {
public:
    /////////////////////////////////////////////////////////////////////////
    //https://www.youtube.com/watch?v=BQ9E-2umSWc&t=74s
    int m1_rabin_karp(string &haystack, string &needle)
    {
        long long shash=0,phash=0,mod=1e9+7;
        int slen=haystack.size() , plen = needle.size();
        
        
        if(plen==0) return 0;       //empty pattern
        if(slen<plen)   return -1;  //string shorter than patt
        
        int i;
        for(i=0;i<plen;i++)
        {
            phash = ((phash*26)%mod  + (needle[i] - 'a' + 1))%mod;  // only lower-case English characters.
                    //lshift       //next char
            shash = ((shash*26)%mod  + (haystack[i] - 'a' + 1))%mod;    //initial window in string
        }
        
        //calculate the base for rightmost element in window
        long long msb_base = 1;
        for(int i=1;i<plen;i++)
            msb_base = (msb_base*26)%mod;
        
        //cout<<phash<<" "<<msb_base<<"\n";
        for(i=0;i<slen-plen+1;i++)
        {
            //cout<<shash<<" "<<haystack.substr(i,plen)<<"\n";
            if(phash==shash)        //hash values are same
            {
                int j;
                for(j=0;j<plen;j++)     //check if pattern is same
                    if(haystack[i+j] != needle[j])
                        break;
                if(j==plen)         //pattern found
                    return i;       
            }
            
            //roll the  hash value
            shash -= (msb_base*(haystack[i]-'a' + 1))%mod;      //remove leftmost char in window
            if(shash<0)     //if hash becomes negative
                shash += mod;
            shash %= mod;
            shash = ((shash*26)%mod + (haystack[i + plen]-'a' + 1))%mod;    //add next char in the window
        }
        
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////
    //https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
    int* pref_suff_arr(string &pat)
    {
        int n=pat.size();
        int prefsuf[n];
        prefsuf[0]=0;
        int j=0;
        
        for(int i=1;i<n;)
        {
            if(pat[i]==pat[j])
            {
                prefsuf[i]=j+1;
                j++;
                i++;
            }
            else if(j>0)
                j=prefsuf[j-1];
            else
            {
                prefsuf[i]=0;
                i++;
            }
        }
        return prefsuf;
    }
    
    int m2_KMP(string &haystack, string &needle)
    {
        int slen=haystack.size() , plen = needle.size();
        
        
        if(plen==0) return 0;       //empty pattern
        if(slen<plen)   return -1;  //string shorter than patt
        
        int *presuf =  pref_suff_arr(needle);
        /*for(auto x:presuf)
            cout<<x<<" ";*/
        
        int j=0;
        for(int i=0;i<slen-plen+1;i++)
        {
            if(haystack[i]==needle[0])
            {
                j = j ? presuf[j-1] : 0;
                for(;j<plen;j++)
                    if(haystack[i+j] != needle[j])
                        break;
                
                if(j==plen)
                    return i;
            }
        }
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////
    int strStr(string haystack, string needle) {
        return m1_rabin_karp(haystack, needle);
        //return m2_KMP(haystack, needle);

    }
};
