class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size(),c=0;
        int sum=0;
        unordered_map<int,int> mp;
            
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            
            int t=sum-k;
            if(mp.find(t)!=mp.end())
                c+=mp[t];
            
            if(sum==k)
                c++;
            
            mp[sum]++;
        }
      
        return c;
    }
};
