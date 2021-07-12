
#define ppi pair<int,int>
class Solution {
public:
    int m1_heap_full_matrix(vector<vector<int>>& matrix, int &k)
    {
        priority_queue<int,vector<int> , greater<int>> pq;  //min heap
        for(auto row:matrix)
            for(auto x:row)
                pq.push(x);
        
        for(int i=1;i<k;i++)
            pq.pop();
        
        return pq.top();
    }
    ///////////////////////////////////////////////////////////////////////////
    //similar to external sort
    int m2_one_ele_per_row(vector<vector<int>>& mat, int &k)
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        int n=mat.size();
        for(int i=0; i<n; ++i)
            pq.push({mat[i][0],{i,0}});
        
        int res;
        while(k--)
        {
            res=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col!=n-1)
                pq.push({mat[row][col+1],{row,col+1}});
        }
        return res;
    }
    ///////////////////////////////////////////////////////////////////////////
    //https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85173/Share-my-thoughts-and-Clean-Java-Code
    
    //https://www.youtube.com/watch?v=oeQlc87HbbQ&t=73s
    
    
    //below solution is possible because row and col both are sorted.
    //if only rows were sorted then we would use upper_bound to count LessEqualK elements
    int countLessEqualK(int &k ,vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int row = 0 , col = n-1 , count=0;        //start at top right
        
        while(row<n && col>=0)
        {
            if(matrix[row][col] <= k)
            {
                count += col + 1;
                row++;
            }
            else
                col--;
        }
        return count;
    }
    
    int m3_bsearch(vector<vector<int>>& matrix, int &k)
    {
        int n=matrix.size();
        int low = matrix[0][0] , high = matrix[n-1][n-1];
        
        while(low<high)
        {
            int mid = (high + low) / 2;
            if(countLessEqualK(mid ,matrix) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return high;        //or return low
    }
    ///////////////////////////////////////////////////////////////////////////
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //return m1_heap_full_matrix(matrix , k);
        //return m2_one_ele_per_row(matrix , k);
        return m3_bsearch(matrix , k);

    }
};
