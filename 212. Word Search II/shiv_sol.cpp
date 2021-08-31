/*
1. Using trie if what we are searching was in the dictionary or not 
    - basically not going in the depth of dfs if the word cant be formed with that path
*/

struct trie{
    trie * child[26] = {0};
    bool end_here = false;
    
};
bool isempty(trie * r){
        for(int i = 0 ; i < 26 ; i++ ){
            if(r->child[i]) return false;
        }
        return true;
    }
trie * delete_node(trie * root, int d ,string &s){
    if(!root) return NULL;
    if(d == s.size() && root->end_here){
        root->end_here = false;
        if(isempty(root)) {
            delete(root);
            return NULL;
        }
        return root;

    }
    root->child[(s[d]-'a')] = delete_node(root->child[(s[d]-'a')], d+1, s);
    if(isempty(root) && !root->end_here){
        delete(root);
        return NULL;
    }
    return root;
}
class Solution {
public:
    
    vector<string> result;
    int n , m;
    vector<pair<int,int>> dir;
    bool isvalid(int i , int j){
        if(i < 0 || i > n-1 || j < 0 || j > m-1) return false;
        return true;
    }
    void dfs(int i , int j, trie * &root, vector<vector<char>>& B, string &s){
        s.push_back(B[i][j]);
        // check if such path can exist
        trie* crawl = root;
        for(auto c : s){
            
            if(!crawl || !(crawl->child)[c-'a']){s.pop_back(); return;}
            crawl = (crawl->child)[c-'a'];
        }
        
        // delete current path
        if(crawl->end_here){result.push_back(s); root = delete_node(root,0,s);}
        
        // go on path
        B[i][j] = '*';
        for(auto d : dir){
            int ti = i+d.first , tj = j+d.second;
            if (isvalid(ti,tj) && B[ti][tj] != '*'){
                dfs(ti,tj,root,B,s);
            }
        }
        
        // revert back 
        B[i][j] = s.back();
        s.pop_back();
        
        
    }
    vector<string> findWords(vector<vector<char>>& B, vector<string>& W) {
        // build trie
        trie * root = new trie();
        n = B.size() , m = B[0].size();
        dir = {{-1,0},{0,-1},{1,0},{0,1}};
        
        //inserting words in trie
        for(auto w : W){
            trie * crawl = root;
            for(int i = 0; i < w.size(); i++){
                int c = w[i]-'a';
                
                if(!(crawl->child)[c]) (crawl->child)[c] = new trie();
                crawl = (crawl->child)[c];
                if(i == w.size()-1) crawl->end_here = true;
            }
        }
        
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                string s = "";
                if(root) dfs(i,j,root,B,s);
            }
        }
        
        return result;
    }
};
