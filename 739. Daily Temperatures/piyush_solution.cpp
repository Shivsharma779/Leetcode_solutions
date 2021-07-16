class Solution {
public:
    
    //https://leetcode.com/problems/daily-temperatures/discuss/121787/C%2B%2B-Clean-code-with-explanation%3A-O(n)-time-and-O(1)-space-(beats-99.13)
    
    
    vector<int> dailyTemperatures(vector<int>& a) {
        
        int n=a.size();
        vector<int> res(n);
        res[n-1]=0;
        
        //for each value more than i we assume we know 
        //how many days you would have to wait until a warmer temperature.
        for(int i=n-2;i>=0;i--)
        {
            int j=i+1;
            while(j<n)
            {
                if(a[j]>a[i])
                {
                    res[i]=j-i;
                    break;
                }
                else if(res[j]==0)
                {
                    res[i]=0;
                    break;
                }
                else
                    j+=res[j];  //add jth temprature as all elements 
                                //in i to j have temprature less than a[j]
            }
        }   
        
        return res;
    }
};
