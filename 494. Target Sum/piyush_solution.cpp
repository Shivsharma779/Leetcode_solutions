class Solution {
public:
    
    //https://www.youtube.com/watch?v=hqGa65Rp5LQ
    int findTargetSumWays(vector<int>& a, int s) {
        
        int i=0,csum=0;
       
        int sum=s,n=a.size(),j;
        for(auto x:a)
        {
            sum+=x;
            if(x==0)        //count number of zeros
                csum++;
        }
        if(sum&1)          //odd sum
            return 0;
        
        sum/=2;
        
        //subset sum problem now
        int dp[n+1][sum+1];
        for( i=1;i<=sum;i++)
            dp[0][i]=0;
        for( i=0;i<=n;i++)
            dp[i][0]=1;
        
        for( i=1;i<=n;i++)
            for( j=1;j<=sum;j++)
                if(j<a[i-1] || a[i-1] == 0)     //handles +0,-0 cases
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
                
        return dp[n][sum] * pow(2,csum);
    }
};
