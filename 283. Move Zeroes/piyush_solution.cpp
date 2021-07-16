class Solution {
public:
    void moveZeroes(vector<int>& a) {
        
        int i=0,j,n=a.size();
        while(i<n && a[i]!=0)       //i at first 0
            i++;
        
        j=i+1;
        while(j<n && a[j]==0)       //j at next non zero
            j++;
        
        while(i<n && j<n)
        {
            swap(a[i],a[j]);
            i++;
            j++;
            while(j<n && a[j]==0)       //j at next non zero
                j++;     
        }
    }
};
