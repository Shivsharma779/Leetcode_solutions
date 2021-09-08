class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    //https://www.youtube.com/watch?v=CiiXBvrX-5A
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here 
        int i=0,j=n-1;
        while(i<j)
        {
            if(a[i][j]) //i knows j, so i is not celeb
                i++;        
            else
                j--;
        }
        
        //check if candidate knows anyone else
        for(int j=0;j<n;j++)
            if(a[i][j])
                return -1;
        
        /*
         0 0 0
         0 0 0
         0 0 0
        */
        //cout<<i<<" ";
        
        for(int j=0;j<n;j++)        //everyone knows i
            if(!a[j][i] and j!=i)   
                return -1;
        
         
        return i;
                
    }
};
