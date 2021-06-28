/*
three conditions
1. non overlapping
2. full overlapping
3. partial overlapping

a b c d
a       c       d       b
1. fully overlap  c>=a b>=d
    return a,b
2. partial overlap c>=a && c <= b && d>b
    a   c   b   d
    return a,d
3. no overlap
    a   b   c   d c> b
    return a,b  c,d
sort(end)

*/

struct comp{
    bool operator()(const vector<int> &a , const vector<int> &b){
        if(a[1] < b[1]) return true;
        else if(a[1] == b[1])return (a[0] < b[0]);
        else return false;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        int n = A.size();
        sort(A.begin() , A.end());
        vector<vector<int>> ans;
        ans.push_back(A[0]);
        for(int i =1 ; i < n ; i++){
            vector<int> &B = ans.back();
            if(B[1] >= A[i][0]) B[1] = max(B[1] , A[i][1]);
            else ans.push_back(A[i]);
        }
        
        return ans;
    }
};
