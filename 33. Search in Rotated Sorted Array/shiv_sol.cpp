int find_mid(vector<int> &A, int s, int e){
        while(s<e){
            
            int mid = (s+e)/2;
            if(A[mid] > A[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
    int bs(vector<int> &A, int s, int e,int target){
        while(s<e){
            
            int mid = (s+e)/2;
            if(A[mid] == target){
                return mid;
            }
            else if(A[mid] > target){
                e=mid;
            }
            else s = mid+1;
        }
        return s;
    }
    int search(vector<int>& A, int target) {
        int n = A.size();
        int bpt = find_mid(A,0,n-1);
        int ans = -1;
        if(bpt > 0 && target <= A[bpt-1] && target >= A[0]){
            ans =  bs(A,0,bpt-1,target);
        }
        else ans = bs(A,bpt,n-1,target);
        
        if(A[ans] == target) return ans;
        return -1;
        
    }
