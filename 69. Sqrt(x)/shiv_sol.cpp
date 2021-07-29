class Solution {
public:
    int mySqrt(int x) {
        int low = 0 , high = 46340;
        while(low*low <= high * high){
            int mid = (low+(high-low)/2);
            if(mid*mid == x) return mid;
            else if(mid*mid> x){
                high = mid;
            }
            else{
                if(low == mid) break;
                low = mid;
            }
        }
        return (x >= 46340 * 46340)?46340:low;
    }
};
