class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool neg = false;
        if(x<0){
            neg=1;
            if(x>=INT_MIN+1)x=-x;
            else return 0;
        }
                
        while(x!=0){
            if(ans<=(INT_MAX-x%10)/10){
                ans=ans*10+x%10;
                x/=10;
            }
            
            else return 0;
        }
        
        if(neg) ans =0 -ans;
        return ans;
    }
};
