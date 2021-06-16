class Solution {
public:
    //https://www.youtube.com/watch?v=qJSPYnS35SE&t=328s
    
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>> res;
    
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || a[i]!=a[i-1])
            {
                int sum=0-a[i],l=i+1,r=n-1;     //we find this number
                while(l<r)          //2 pointer in array after fixing i
                {
                    if(a[l]+a[r]==sum)
                    {
                        res.push_back({a[i],a[l],a[r]});
                        while(l<r && a[l]==a[l+1]) l++;        //skip reps at left
                        while(l<r && a[r]==a[r-1]) r--;        //skip reps at right
                        l++;
                        r--;
                    }
                    else if(a[l]+a[r]<sum)                
                        l++;
                    else
                        r--;
                }
            }
            
        }
        
        return res;
            
        
    }
};
