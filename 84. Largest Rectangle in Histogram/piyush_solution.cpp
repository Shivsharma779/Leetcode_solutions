class Solution {
public:
    //https://www.youtube.com/watch?v=vcv3REtIvEo&t=1188s
    int m1_track_left_right(vector<int>& hist)
    {
        if(hist.size()==0)
            return 0;
        
        int n=hist.size(),res=0,temp,right;
        int left[n];
        stack<int> st1,st2;
        
        for(int i=0;i<hist.size();i++)
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
            
            temp=hist[i]*(right-left[i]+1);
            res=max(res,temp);
        }
        
        
        return res;
    }
    ///////////////////////////////////////////////////////////////////////
    int m2_track_left(vector<int>& hist)
    {
        stack<int> st;
        int n=hist.size() , res=0 , height , width, i=0;
        for( ;i<n;i++)
        {
            while(!st.empty() && (hist[st.top()] > hist[i]))
            {
                height = hist[st.top()];
                width = i - st.top();
                //cout<<height <<" "<<width<<"\n";
                res = max(res , height * width);
                st.pop();
            }
            st.push(i);
        }
        
        //pop remaining
        while(!st.empty())
        {
            height = hist[st.top()];
            width = i - st.top();
            //cout<<height <<" "<<width<<"\n";

            res = max(res , height * width);
            st.pop();
        }
        
        return res;
        
    }
    ///////////////////////////////////////////////////////////////////////
    int largestRectangleArea(vector<int>& hist) {
        return m1_track_left_right(hist);
        //return m2_track_left(hist);
        
    }
};
