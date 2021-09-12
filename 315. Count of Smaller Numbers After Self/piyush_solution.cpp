class Solution {
public:
    //https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)
    
    //vector take more space and time
    
    //in merge sort count elements shifted from right part to left. Those decide count of smaller elements on right of each ele.
    void mergesort(int st , int ed ,vector<int> &res, pair<int,int> arr[])
    {
        if(st<ed)
        {
            int mid = (st+ed)/2;
            mergesort(st,mid,res,arr);
            mergesort(mid+1,ed,res,arr);
            
            pair<int,int> temp[ed-st+1];
            int i=st , j=mid+1 , k=0 , countshiftleft=0;
            
            while(i<=mid && j<=ed)
            {   
                //smaller element in right part
                if(arr[i].first > arr[j].first)
                {
                    //number of elements moved from right part
                    countshiftleft++;
                    temp[k++] = arr[j++];
                }
                else
                {
                    //countshiftleft has number of element moved from right part which are 
                    //smaller than current ele.
                    res[arr[i].second] += countshiftleft;
                    temp[k++] = arr[i++];
                }
            }
            
            while(i<=mid)
            {
                res[arr[i].second] += countshiftleft;
                temp[k++] = arr[i++];
            }
            
            while(j<=ed)
            {
                countshiftleft++;
                temp[k++] = arr[j++];
            }
            
            i=st;
            for(auto &x:temp)
                arr[i++]=x;
        }
    }
    
    
    vector<int> countSmaller(vector<int> &nums) {
        int n=nums.size();
        if(n==0)
            return nums;
        pair<int,int> arr[nums.size()];
        
        for(int i=0;i<n;i++)
            arr[i]={nums[i] , i};       //val,idx
        
        nums = vector<int>(n , 0);
        mergesort(0,n-1,nums,arr);
        return nums;
    }
};
