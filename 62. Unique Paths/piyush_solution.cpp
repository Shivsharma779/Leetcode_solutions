class Solution {
public:
  //ncr
    int uniquePaths(int m, int n) {
        long long res=1;
        m--;
        n--;
        int r=min(m,n);
        for(int i=1;i<=r;i++)
            res = res* (i+max(m,n)) /i;
        return res;
    }
};
