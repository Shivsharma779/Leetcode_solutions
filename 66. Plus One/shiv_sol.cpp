class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        // int n = d.size();
        
        for(int i = d.size()-1; i>-1;i--){
            if(d[i] != 9){
                d[i]++;
                return d;
                
            }
            else{
                d[i] = 0;
            }
        }
        d.push_back(0);
        d[0] = 1;
        return d;
        
    }
};
