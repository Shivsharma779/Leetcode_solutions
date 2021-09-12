class Solution {
public:
    vector<int> ans;
    void mergesort(vector<int> &A , vector<int> &ind, int l , int r){
        if(l<r){
            int mid = (l+r)/2;
            mergesort(A,ind,l,mid);
            mergesort(A,ind,mid+1,r);
            merge(A,ind,l,mid,r);            
        }
    }
    
    void merge(vector<int> &A , vector<int> &ind, int l ,int m, int r){
        // ls  = left_size , 
        int ls = m-l+1;
        int rs = r-m;
        vector<int> L(ls) , R(rs);
        for(int i = 0 ; i < ls ; i++ ) L[i] = ind[l+i];
        for(int i = 0 ; i < rs ; i++ ) R[i] = ind[m+1+i];
        
        int i = 0 , j = 0, k = l, rc = 0;
        while(i < ls && j < rs){
            if(A[L[i]] <= A[R[j]]){
                
                // 2    1
                ind[k] = L[i++];
                ans[ind[k]] += rc;
            }
            else{
                ind[k] = R[j++];
                rc++;
            }
            k++;
        }
        while(i<ls){
                ind[k] = L[i++];
                ans[ind[k]] += rc;
                k++;
        }
        while(j<rs){
                ind[k] = R[j++];
                k++;
        }
        
    }
    vector<int> countSmaller(vector<int>& A) {
        int n = A.size();
        ans = vector<int>(n,0);
        vector<int> ind(n);
        for(int i = 0 ; i < n ; i++) ind[i] = i;
        mergesort(A,ind,0,n-1);
        return ans;
    }
};

// 2 5 1 6
