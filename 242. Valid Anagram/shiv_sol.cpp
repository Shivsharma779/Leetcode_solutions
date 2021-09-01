class Solution {
public:
    bool isAnagram(string &s, string &t) {
        vector<int> A(26,0) , B(26,0);
        for(auto &c: s){
            A[c-'a']++;
        }
        for(auto &c: t){
            B[c-'a']++;
        }
        if(A == B) return true;
        else return false;
       
    }
};
