struct Line{
    double slopey;
    double slopex;
    double intercept; 
};
struct hash_pair{
    size_t operator()(const pair<int,int> &a ) const{
        hash<int> a_hash , b_hash;
        // auto b_hash = hash<int>{}(a.second);
        
        return a_hash(a.first) ^ b_hash(a.second); 
    }
};

class Solution {
public:
    
   int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        unordered_map<pair<int, int>, int,hash_pair> slope_map{};
        // std::sort(points.begin(), points.end());
        
        int max_count = 1;
        for(int i =0 ; i < points.size() -1; i++) {
            int dup = 0;
            int horizon = 1;
            slope_map.clear();
            for(int j = i + 1; j < points.size(); j++) {
                if (points[i] == points[j]) {
                    dup += 1;
                } else {
                    int x1= points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    if (y1 == y2) {
                        horizon += 1;
                        max_count = max(horizon + dup, max_count);
                    } else {
                        auto slope = cal_slope(x1 - x2, y1 - y2);
                        if (slope_map.count(slope) == 0) {
                            slope_map[slope] = 2;
                        } else {
                            slope_map[slope]++;
                        }
                        max_count = max(slope_map[slope] + dup, max_count);
                    }
                }
            }
        }
        return max_count;
    }
    
    pair<int, int> cal_slope(int x, int y) {
        int GCD = gcd(x, y);
        return {x/GCD, y/GCD};
    }
    
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
     
    }
};
