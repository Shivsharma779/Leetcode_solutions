class Solution {
public:
    static bool comp(int &n1,int &n2)
    {
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        return s1+s2 > s2+s1;           //whichever combination is greater
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),comp);
        
        string res = "";
        for(auto s:nums)
            res += to_string(s);
        
        int i=0,n=res.size();
        for(;i<n;i++)           //remove leading zeros
            if(res[i]!='0')
                break;
            
        return (i==n) ? "0" : res.substr(i);    //case if all numbers are zeros
    }
};
