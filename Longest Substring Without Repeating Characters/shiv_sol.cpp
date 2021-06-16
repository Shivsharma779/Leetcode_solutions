class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // fill dp
        unordered_map<char,int> m;
        int ans = 0;
        int counter = 0;
        for(int i  = 0 , j = 0; i < n, j< n ; j++){
            
            if(m.find(s[j]) == m.end()){
                m[s[j]] = j;
                // cout << "found" s[i]
            }
            else{
                if (i<=  m[s[j]]) i =  m[s[j]]+1;
                m[s[j]] = j;
            }
            counter = j-i+1;
            if(counter > ans) ans = counter;
            // cout << counter << " " << j << " " << i << "||";
        }
        return ans;
    }
};
