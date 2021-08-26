class Solution {
public:
    //https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
    //https://www.youtube.com/watch?v=M9cVl4d0v04
    int m1_normal_BFS(string &beginWord, string &endWord, vector<string>& wordList)
    {
        unordered_set<string> mp(wordList.begin(), wordList.end());

        if(mp.find(endWord)==mp.end())
            return 0;
        
        queue<string> q;
        int level = 1;
        
        q.push(beginWord);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string cur_word = q.front();
                q.pop();
                
                if(cur_word == endWord)
                    return level;
                
                mp.erase(cur_word);         
                
                for(int j=0;j<cur_word.size();j++)
                {
                    char c = cur_word[j];
                    for(char k= 'a';k<= 'z';k++)
                    {
                        cur_word[j] = k;
                        if(mp.find(cur_word) != mp.end())
                            q.push(cur_word);
                    }
                    cur_word[j] = c;
                }
            }
            
            level++;
        }
        return 0;
    }
    ////////////////////////////////////////////////////////////////////////////////
    //https://leetcode.com/problems/word-ladder/discuss/549175/Bi-Directional-BFS-and-naive-BFS
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
    ////////////////////////////////////////////////////////////////////////////////
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //return m1_normal_BFS(beginWord,endWord,wordList);
        return m2_bidirectional_BFS(beginWord,endWord,wordList);

    }
};
