class Solution {
public:

    int maxRectHistogram(vector<char>& hist,int &n)
    {
        int res=0;
        int left[n],right;
        stack<int> st1,st2;
        
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && hist[st1.top()]>=hist[i])
                st1.pop();
            
            if(st1.empty())
                left[i]=0;
            else
                left[i]=st1.top()+1;
            
            st1.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && hist[st2.top()]>=hist[i])
                st2.pop();
            
            if(st2.empty())
                right=n-1;
            else
                right=st2.top()-1;
            st2.push(i);
            
            int len = (right - left[i] + 1);
            res=max(res , hist[i] * len);
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& arr) 
    {
        int m=arr.size();
        if(m==0)
            return 0;
        int n = arr[0].size();
        if(n==0)
            return 0;
                
        //create histogram for each row
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(i==0)
                    arr[i][j]-='0';
                else if(arr[i][j]=='0')
                    arr[i][j]=0;
                else
                    arr[i][j]=arr[i-1][j]+1;
        
        int res=0 , cur;
        for(auto row:arr)
            res = max(res , maxRectHistogram(row,n) );
        
        return res;
    }
};
