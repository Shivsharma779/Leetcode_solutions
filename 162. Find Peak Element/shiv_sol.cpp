class Solution {
public:
    int findPeakElement(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int ml = (mid>0)?A[mid-1]:INT_MIN;
            int mr = (mid<n-1)?A[mid+1]:INT_MIN;
            
            if(A[mid]>ml && A[mid] > mr) return mid;
            else if(ml>mr) r=mid-1;
            else l = mid+1;
        }
        return 0;
    }
};
