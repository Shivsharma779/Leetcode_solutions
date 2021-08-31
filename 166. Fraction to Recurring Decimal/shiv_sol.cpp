class Solution {
public:
    string fractionToDecimal(int a, int b) {
       string ans;
    if(a == 0) return "0";
    if((a < 0 )^ (b < 0)) ans.push_back('-');
    
    long long int n = labs(a) , d = labs(b);
    ans += to_string(n/d);
    n = n % d;
    if(!n) return ans;
    
    ans.push_back('.');
    
    
    unordered_map<long long int,long long int> m;
    while(n){
        if( m.find(n) != m.end() ){
            ans.insert(m[n%d],"(");
            ans.push_back(')');
            return ans;
        }
        
        m[n] = ans.size();
        
        n*=10;
        ans += to_string(n/d);
        n = n%d;
        
    }
    return ans;
}

};
