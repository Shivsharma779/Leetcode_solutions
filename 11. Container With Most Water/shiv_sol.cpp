class Solution {
public:
      int maxArea(vector<int>& height) {
          int n = height.size();
          int ans = 0, l = 0 , r = n -1, h ,b;
        while(l<r){
            h = min (height[l], height[r]);
            b = r -l ;
            ans = max(ans,h*b);
            if(height[l] < height[r]) {
                l++;
            }
            else{
                r--;
            }             
        }
        
        return ans;
    }
};
