class Solution {
public:
    int divide(int dividend, int divisor);
};

// a / b
int Solution::divide(int a, int b) {
    // First, deal with bunch of special conditions
    if (a == b) 
        return 1;
    
    if (b == 1) 
        return a;
    
    if (a == 0 || b == INT_MIN) 
        return 0;
    
    if (a == INT_MIN && b == -1) 
        return INT_MAX; // seems to be the only condition to max out...
    
    
    // get sign 
    int sign = 1;
    if ((a >> 31) ^ (b >> 31)) {
        sign = -1;
    }
    // convert both to negative
    if (a > 0) a = -a;
    if (b > 0) b = -b;
    if (b < a) return 0;
    

    int res = 0;
    int sub = b;
    int cnt = 1;
    // you can use bit here, shift is the same as b * 2 or b + b
    while (true) {
        while (sub >= INT_MIN / 2 && a - (sub + sub) < 0) {
            sub += sub;
            cnt += cnt;
        }
        a -= sub;
        res += cnt;
        // re-init
        sub = b;
        cnt = 1;
        if (a > b) {
            break;
        }
    }
    return sign > 0 ? res : -res;
}
