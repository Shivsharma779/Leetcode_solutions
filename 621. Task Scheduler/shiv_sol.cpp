class Solution {
public:
    int leastInterval(vector<char>& A, int N) {
        
        unordered_map<char,int> m;
        int n = A.size();
        
        
        for(int i = 0; i < n ; i++){
            m[A[i]]++;
        }
        
        int max_count = 0;
        int no_with_max_count = 0;
        for(auto a : m){
            if(a.second > max_count){
                max_count = a.second;
            }
        
        }
        for(auto a : m){
            if(a.second == max_count){
                no_with_max_count ++;
            }
        
        }
        
        return max(n, max_count + (max_count-1) * (N) + (no_with_max_count-1));
        
        
        
    }
};
