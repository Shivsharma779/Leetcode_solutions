class Node{
    public:
    vector<Node*> children;
    bool ends;
    Node(){
        children = vector<Node *>(26,NULL);
        ends = false;
    }
    
        
};

class Trie {
public:
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        int n = s.size();
        Node * crawl = root;
        for ( int i = 0 ; i < n ; i++ ){
            int index = s[i] - 'a';
            
            
            if(!(crawl->children[index])){
                crawl->children[index] = new Node();
            }
            crawl = crawl->children[index];
            
        }
        
        crawl->ends = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
        int n = s.size();
        Node * crawl = root;
        for ( int i = 0 ; i < n ; i++ ){
            int index = s[i] - 'a';
            if(!(crawl->children[index])){
                return false;
            }
            crawl = crawl->children[index];
            
        }
        
        if(crawl->ends) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        int n = s.size();
        Node * crawl = root;
        for ( int i = 0 ; i < n ; i++ ){
            int index = s[i] - 'a';
            if(!(crawl->children[index])){
                return false;
            }
            crawl = crawl->children[index];
            
        }
        
        return true;
    }
};
