class Solution {
public:
    bool canJump(vector<int>& a) {
        int lastpos=a.size()-1,i;
        for(i=a.size()-1;i>=0;i--)
        {
            if(i + a[i] >= lastpos)
                lastpos=i;
        }
        return lastpos==0;
    }
};
