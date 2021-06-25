#define equal 0
#define smaller 1
#define greater 2




class Solution {
public:

    
    
    int check(unordered_map<char,int> &sc, unordered_map<char,int> &tc){
        // int ans = equal;
        for(auto &c : tc){
            // cout << "comparison " <<  c.first << " " << sc[c.first] << " " << tc[c.first]  << endl;
            if(sc[c.first] < tc[c.first]) return smaller;
            // else if(sc[c.first] > tc[c.first]) return greater;
        }
        return equal;
    }
    string minWindow(string &s, string &t) {
        int n = s.size() , m = t.size();
        if( m > n) return "";
        string ans = "#";
        unordered_map<char,int> sc;
        unordered_map<char,int> tc;
        for(auto c : t) tc[c]++;
        
        int i = 0, j = 0;
        while(j < n){
            // cout << "-----------------\n";
            // for(auto c : tc) cout << c.first << " " << sc[c.first] << " " << tc[c.first] << endl;
            // cout << s.substr(i,j-i+1) << endl;
            if(tc.find(s[j]) == tc.end()) {j++; continue;}
            sc[s[j]]++;
            // for(auto c : tc) cout << c.first << " " << sc[c.first] << " " << tc[c.first] << endl;
            // cout << "-----------------\n";

            int x = check(sc,tc);
            
            if(x != smaller){
                while(check(sc,tc) != smaller ){
                    // for(auto c : tc) cout << c.first << " " << sc[c.first] << " " << tc[c.first] << endl;
                    // cout << ans <<" " <<  s.substr(i,j-i+1) ;
                    
                    ans = (j-i+1 < ans.size() || ans == "#")?s.substr(i,j-i+1):ans;
                    sc[s[i]]-- ,i++;  
                    // cout << " to " <<  s.substr(i,j-i+1) << endl;
                    // for(auto c : tc) cout << c.first << " " << sc[c.first] << " " << tc[c.first] << endl;
                }
                
            }
            
            j++;
            
            
        }
        return (ans == "#")?"":ans;
    }
};
