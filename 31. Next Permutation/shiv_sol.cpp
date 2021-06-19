void nextPermutation(vector<int>& A) {
        int n = A.size();
        long long i;
        for( i =n-2 ; i > -1; i--){
           if(A[i] < A[i+1]) break;
        }
        if(i == -1){
            reverse(A.begin(),A.end());
            
        }
        else{
            int j = n-1;
            while(A[i] >= A[j]) j--;
            swap(A[i],A[j]);
            reverse(A.begin()+i+1,A.end());
        }
        
    }
