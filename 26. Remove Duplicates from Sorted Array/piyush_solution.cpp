class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i=1,j=1,n=a.size();
        if(n==0)
            return 0;
        
        // j keeps track of repeated element, i checks if current element is 
        //seen for the first time. if yes then it places element at j and both pointers 
        // move forward. If i element is repeated then we move fwd and chk for new 
        // unique element
        while(i<n)
        {
            if(a[i]!=a[i-1])    //skip repeats               
            {
                a[j]=a[i];
                j++;
            }
            i++;
        }
        return j;
    }
};
