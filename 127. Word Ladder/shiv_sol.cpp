#define correct 0
#define not_correct 1
class Solution {
public:
    int check(string &a, string &b){
        int diff_found = 0;
        int n = a.size();
        for(int i = 0 ; i < n ; i++){
            bool diff = a[i] - b[i];
            if(diff != 0) diff_found++;
            if(diff_found > 1) return not_correct;
        }
        return (diff_found == 0)?not_correct:correct;
    }
    int ladderLength(string &b, string &e, vector<string>& W) {
        queue<string> q;
        unordered_set<string> dict(W.begin(),W.end());
        if (dict.find(e) == dict.end()) return 0;
        int ans = 1;
        q.push(b);
        if(dict.find(b) != dict.end()) dict.erase(b);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string word = q.front();
                q.pop();
                if(word == e) return ans;
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                            
                        }
                     }
                    word[j] = c;
                }
            }
            ans++;
        }
        return 0;
    }
};
