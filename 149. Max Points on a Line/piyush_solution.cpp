class Solution {
public:
    //logic
    //https://www.youtube.com/watch?v=0GTjD5yfkkQ
    
    //theory
    //https://leetcode.com/problems/max-points-on-a-line/discuss/47124/C%2B%2B-slope-counter
    int maxPoints(vector<vector<int>>& points) {
        int gmax=0 , n=points.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<string,int> slopes;
            int duplicates = 1;
            for(int j=i+1;j<n;j++)
            {
                //duplicate point
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    duplicates++;
                //x-coord same then infinite slope
                else if(points[i][0]==points[j][0])
                    slopes["inf"]++;
                //convert slope to string for easier hashing
                else
                {
                    int mx = points[i][0] - points[j][0];
                    int my = points[i][1] - points[j][1];
                    int hcf = __gcd(mx,my);
                    mx/=hcf;
                    my/=hcf;
                    slopes[to_string(mx) + "|"  + to_string(my)]++;
                }
            }
            
            int cmax=0;
            for(auto x:slopes)
                cmax = max(cmax , x.second);
            cmax += duplicates;
            
            gmax = max(cmax , gmax);
        }
        
        
        //cout<<__gcd(-2,-3)<<" "<<__gcd(2,-3)<<" "<<__gcd(-2,3)<<" ";
        return gmax;
    }
};
