class Solution {
public:
    unordered_map<string, unordered_set<string>> adj;
    
    void helper( string &end, unordered_set<string> &mp,
                vector<string> &temp ,vector<vector<string>> &res, int &minlv,
                unordered_set<string> &curlv)
    {
        
        vector<string> call;
        //cout<<beg<<" ";
        /*
        for(auto s:temp)
            cout<<s<<" ";
        cout<<endl;
        */
        if(temp.size() > minlv)
            return;

        unordered_set<string> nextlv;
        
        for(auto beg:curlv)
        {
            if(temp.size() == minlv)
            {
                if(beg==end)
                    res.push_back(temp);
                return;
            }
            
            
            for(int i=0;i<beg.size();i++)
            {
                char cur_char = beg[i];
                for(char  c='a';c<='z';c++)
                {
                    if(cur_char != c)
                    {
                        string old = beg;
                        beg[i]=c;
                        if(mp.find(beg)!=mp.end() && curlv.find(beg)==curlv.end())
                        {
                            adj[old].insert(beg);
                            call.push_back(old);
                            nextlv.insert(beg);
                        }
                    }
                }
                beg[i] = cur_char;
            }
        }
        
        for(auto old:call)
        {
            for(auto beg:adj[old])
            {    
                mp.erase(beg);
                temp.push_back(beg);
                helper(end,mp,temp,res,minlv,nextlv);
                temp.pop_back();
                mp.insert(beg);
            }
        }
    }
    
    
    //////////////////////////////////////////////////
    int m2_bidirectional_BFS(string &beginWord, string &endWord, vector<string>& wordList)
    {
        unordered_set<string> mp(wordList.begin(), wordList.end()) , mp1 , mp2;
        int level = 1;
        if(mp.find(endWord) == mp.end())    
            return 0;
        
        mp1.insert(beginWord);
        mp2.insert(endWord);
        
        while(!mp1.empty() && !mp2.empty())
        {
            if(mp1.size() > mp2.size())
                swap(mp1,mp2);           //apply traversal on smaller depth for alternating
            
            unordered_set<string> next_level;
            for(auto word:mp1)
            {
                for(int i=0;i<word.size();i++)
                {
                    char cur_char = word[i];        //store char to restore

                    for(char k = 'a' ; k<= 'z' ; k++)
                    {
                        word[i]=k;
                        if(mp2.find(word)!=mp2.end())   //intermediate word found (mp2 is the last level traversed)
                            return level+1;
                        
                        if(mp.find(word)!=mp.end())     //if word found then insert for next level of traversal
                        {
                            mp.erase(word);
                            next_level.insert(word);
                        }
                    }
                    word[i] = cur_char;         //restore original char
                }
            }
            mp1 = next_level;
            level++;
        }
        
        return 0;
    }
    ///////////////////////////////////////////////////////////////////
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> temp;
        unordered_set<string> mp(wordList.begin(),wordList.end()),curlv;
        
        if(mp.find(endWord)==mp.end())
            return res;
        
        int minlv = m2_bidirectional_BFS(beginWord,endWord,wordList);
        //cout<<minlv;
        temp.push_back(beginWord);
        curlv.insert(beginWord);
        
        helper(endWord,mp,temp,res,minlv,curlv);
        
        return res;
    }
};



/*

cet
cdt

[cot, ]
*/
