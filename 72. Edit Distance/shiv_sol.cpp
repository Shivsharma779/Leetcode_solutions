class Solution {
public:
  
    int minDistance(string w2, string w1) {
        int n = w1.size() ,  m = w2.size();
        int *pre = new int[m+1] ,*curr = new int[m+1];
        
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0; j <= m ; j++){
                
                if(i > 0){ 
                    if( j == 0) curr[j] = pre[j] + 1;
                    else{
                        int cost = 1;
                        if(w1[i-1] == w2[j-1]) cost = 0;
                        curr[j] = min(cost + pre[j-1] , 1 + min(pre[j], curr[j-1]));
                        
                    }}
                else
                    curr[j] = (j==0)?0: 1 + curr[j-1];

            }
            swap(pre,curr);
        }
       
        return pre[m];
    }
};
