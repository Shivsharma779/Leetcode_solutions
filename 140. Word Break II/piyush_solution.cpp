class Solution {
public:
    void m1_helper(string &s,string word,string sentence, vector<string> &res, int i, unordered_map<string,bool> &mp , int &maxlen)
    {
        if(i>=s.size() && mp.find(word) != mp.end())    //sentence ends and last word is found
        {
            sentence += " " + word;     
            res.push_back(sentence.substr(1));      //erase 1st space
            //cout<<sentence<<"\n";
        }
        else if(i<s.size())
        {
            word += s[i];
            if(word.size()<=maxlen && mp.find(word) != mp.end())     //word does not exceed max word size in dict and it exists in dictionary
            {
                m1_helper(s,"",(sentence + " " + word),res,i+1,mp,maxlen);
            }
            m1_helper(s,word,sentence,res,i+1,mp,maxlen);       //append s[i] to current word
        }
    }
    
    vector<string> m1_BT(string &s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> mp;
        int maxlen = 0;
        for(auto s:wordDict)
        {
            mp[s]=1;
            maxlen = max(maxlen , (int)s.size());
        }
        
        vector<string> res;
        string word="",sentence="";
        
        m1_helper(s,word,sentence,res,0,mp,maxlen);
        
        return res;
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return m1_BT(s,wordDict);
    }
};
