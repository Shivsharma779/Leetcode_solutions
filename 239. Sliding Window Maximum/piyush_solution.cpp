class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int i=0,n=a.size();
        vector<int> res;
        deque<int> dq;
        
        for(i=0;i<k;i++)
        {
            while(!dq.empty() && a[i]>=a[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for(;i<n;i++)
        {
            res.push_back(a[dq.front()]);
            while(!dq.empty() && dq.front()<=(i-k))
                dq.pop_front();
            while(!dq.empty() && a[i]>=a[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(a[dq.front()]);
        return res;
    }
};
