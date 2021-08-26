class Solution {
public:
    bool isPalindrome(string &s) {
        // low
        if(s.size() < 2) return true;
        int i = 0 , j = s.size()-1;
        while(i<j){
            if(!isalnum(s[i]))i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i]) != tolower(s[j])) return false;
            else i++, j--;
        }
        return true;
    }
};
