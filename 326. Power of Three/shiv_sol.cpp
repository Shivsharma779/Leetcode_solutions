class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        
        int t = log10(n)/log10(3);
        
        return (n == (int)pow(3, t));
    }
}
