struct min_heap_comp{
    bool operator()(const int &a, const int &b){ return a > b;}
    
};

struct max_heap_comp{
    bool operator()(const int &a, const int &b){ return a < b;}
    
};

class MedianFinder {
public:
    priority_queue<int,vector<int>,max_heap_comp> small;
    priority_queue<int,vector<int>,min_heap_comp> big;

    /** initialize your data structure here. */
    MedianFinder() {
        small = priority_queue<int,vector<int>,max_heap_comp>();
        big = priority_queue<int,vector<int>,min_heap_comp>();
    }
    
    void addNum(int num) {
        small.push(num);
        if(small.size() > big.size() ){
            big.push(small.top());
            small.pop();
        }
        if(small.top() > big.top()){
            int x = small.top();
            int y = big.top();
            
            small.pop();
            big.pop();
            
            small.push(y);
            big.push(x);
        }

        
    }
    
    double findMedian() {
        if(big.size() > small.size()) return big.top();
        else{
            return ((double) big.top() + small.top())/2;
        }
    }
};
