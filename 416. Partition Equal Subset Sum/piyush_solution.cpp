class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum=0,n=a.size(),i,j;
        for(auto x:a)
            sum+=x;
        if(sum&1)          //odd sum
            return 0;
        
        sum/=2;
        bool dp[n+1][sum+1];
        for( i=1;i<=sum;i++)    //sum>0 and select atleast 1 ele
            dp[0][i]=0;
        for( i=0;i<=n;i++)      //sum=0, select no ele
            dp[i][0]=1;
        
        for( i=1;i<=n;i++)
            for( j=1;j<=sum;j++)
                if(j<a[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
        
        return dp[n][sum];
            
        
    }
};
