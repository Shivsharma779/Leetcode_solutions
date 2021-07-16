class Solution {
public:
    
    
    int majorityElement(vector<int>& a) {
        int n=a.size();
        int maxe=a[0],c=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]==maxe)
                c++;
            else
                c--;
            
            if(c==0)
            {
                maxe=a[i];
                c=1;
            }
        }
        return maxe;
    }
};
