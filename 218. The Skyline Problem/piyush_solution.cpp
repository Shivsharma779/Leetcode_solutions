class Solution {
public:
    //Explaination
    //https://www.youtube.com/watch?v=GSBLe8cKu0s&t=1120s
    
    //code implement
    //https://leetcode.com/problems/the-skyline-problem/discuss/490804/C%2B%2B-Clean-and-simple-O(nlogn)-solution-Detailed-Explanantion
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> res;
        vector<pair<int,int>> corners;
        multiset<int> heights;
        
        for(auto tuple:buildings)
        {
            //We make the start height -ve(so that sorting puts it in front)
            corners.push_back({tuple[0] , -1 * tuple[2]});      
            corners.push_back({tuple[1] , tuple[2]});
        }
        
        sort(corners.begin() , corners.end());
        
        heights.insert(0);      //base height
        int cur_max=0 , prev_max = 0;
        
        for(auto coord:corners)
        {
            if(coord.second<0)      //start point
                heights.insert(-1 * coord.second);
            else                //end point
                heights.erase(heights.find(coord.second));       //remove height
            
            cur_max = *(heights.rbegin());      //max height at end of multiset
            
            if(cur_max != prev_max)
            {
                res.push_back({ coord.first , cur_max });
                prev_max  = cur_max;
            }    
        }
        
        return res;
    }
};
