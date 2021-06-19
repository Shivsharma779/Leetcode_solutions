class Solution {
    //https://www.youtube.com/watch?v=quAS1iydq7U&t=517s
public:
    void swap(int &a,int &b)
    {
        int t=a;
        a=b;
        b=t;
    }
        
    void nextPermutation(vector<int>& a) {
        int anc, i = a.size()-2;
        for(;i>=0;i--)
            if(a[i]<a[i+1])      //not strictly decreasing seq
                break;
        
        if(i==-1)       //already last permutation of the array
        {
            reverse(a.begin(),a.end());
            return;
        }
        
        anc = i;  
        i = a.size()-1;               
    
        //find smallest number larger than anchor and swap
        for(;i>=0;i--)
        {    
            if(a[i]>a[anc])
            {
                swap(a[i],a[anc]);
                break;
            }
        }
        
        //reverse to find first permutation after the anchor
        reverse(a.begin()+anc+1 , a.end());
    }
};
