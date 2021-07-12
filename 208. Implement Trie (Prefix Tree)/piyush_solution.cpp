class trienode{
    public:
    bool isword=false;    
    trienode* next[26]={};
};


class Trie {
public:
    /** Initialize your data structure here. */
    trienode *root;
    Trie() {
        root = new trienode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        trienode *cur=root;
        for(int i=0;i<word.size();i++)
        {
            if(cur->next[word[i] - 'a'])      //this char branch already exists       
                cur = cur->next[word[i] - 'a'];  
            else                                //new branch            
            {
                trienode *temp = new trienode();
                cur->next[word[i] - 'a'] = temp;
                cur=temp;
            }
                          
        }
        //mark last character of word as complete word
        cur->isword = true;
                    
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        trienode *cur=root;
        for(auto c:word)
        {
            if(cur->next[c - 'a'])       //character matched
                cur=cur->next[c - 'a'];
            else
                return false;
        }
        
        if(cur->isword)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size(),i;                
        trienode *cur=root;
        
        for(auto c:prefix)
        {
            if(cur->next[c - 'a'])       //character matched
                cur=cur->next[c - 'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
