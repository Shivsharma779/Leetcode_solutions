class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n=a.size(),i;
        for(i=1;i<n;i++)
            a[0]^=a[i];
        return a[0];
    }
};
