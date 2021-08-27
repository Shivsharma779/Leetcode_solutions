class Solution {
public:
    int n;
   
    int canCompleteCircuit(vector<int>& G, vector<int>& C) {
        n = G.size();
        int sum =0, gas = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += G[i] - C[i];
            gas += G[i] - C[i];
            
            if(gas < 0){
                ans = i+1;
                gas = 0;
            }
        }
        return (sum<0)?-1:ans;
        return -1;
    }
};
