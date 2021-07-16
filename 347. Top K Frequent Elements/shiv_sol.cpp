class Compare{
public:
    bool operator ()(pair<int,int> X, pair<int,int> Y){
        if(X.first > Y.first) return true;
        return false;
    }
    
};

class Solution {
public:
   
    vector<int> topKFrequent(vector<int>& A, int k) {
        unordered_map<int,int> m;
        int n = A.size();
        for(int i = 0 ; i < n ; i++){
            m[A[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x: m){
            pq.push({x.second,x.first} );
            // while(pq.size() > k) pq.pop();
            
        }
        vector<int> ans;
        for(int i = 0 ; i < k; i++) {ans.push_back(pq.top().second); pq.pop();}
        return ans;
    }
};
