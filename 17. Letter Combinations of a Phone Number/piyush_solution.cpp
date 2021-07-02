class Solution {
public:
    void findpermut(string &num,vector<string> &dict,int i,string permut,vector<string> &res)
    {
        if(i==num.size())
            res.push_back(permut);
        else
        {
            string keys=dict[num[i]-'0'];
            
            for(int j=0;j<keys.size();j++)
                findpermut(num,dict,i+1,permut+keys[j],res);
        }
    }
    vector<string> letterCombinations(string num)
    {
        
        vector<string> dict{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},res;
        if(!num.size())
            return res;
        
        string permut;
        findpermut(num,dict,0,permut,res);
        return res;
    }
};
