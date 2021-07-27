int Solution::reverse(int n) {
 
    int rev = 0;
        
    while(n)
    {
        if(INT_MAX/10 < rev || (INT_MAX/10 == rev && (n%10 > 7) ))
            return 0;
        if(INT_MIN/10 > rev || (INT_MIN/10 == rev && (n%10 > 8) ))
            return 0;
            
            
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}
