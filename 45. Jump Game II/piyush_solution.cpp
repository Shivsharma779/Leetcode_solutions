class Solution {
public:
    // https://www.youtube.com/watch?v=PEgwWGoKUaY&t=603s
    
    int jump(vector<int>& a) {
        int n=a.size(),
        range=0,            //to mark end of current jump
        pos=0,              //mark where jump took place
        jumps=0;            //count no of jumps
            
        for(int i=0;i<n-1;i++)
        {
            range = max(range,i + a[i]);
            if(pos==i)
            {
                jumps++;
                pos=range;
            }
        }
        return jumps;
    }
};
