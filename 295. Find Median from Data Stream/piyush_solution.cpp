class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double> left;
    priority_queue<double,vector<double>,greater<double>> right;
    double median=0;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize=left.size(),rsize=right.size();
        if(num<median)         //left of median
        {
            if(lsize<rsize)
            {
                left.push(num);
                median=(left.top()+right.top())/2;
            }
            else if(lsize>rsize)
            {
                right.push(left.top());
                left.pop();
                left.push(num);
                median=(left.top()+right.top())/2;    
            }
            else
            {
                left.push(num);
                median=left.top();
            }
        }
        else            //right of median
        {
            if(lsize<rsize)
            {
                left.push(right.top());
                right.pop();
                right.push(num);
                median=(left.top()+right.top())/2;
            }
            else if(lsize>rsize)
            {
                right.push(num);
                median=(left.top()+right.top())/2;    
            }
            else
            {
                right.push(num);
                median=right.top();
            }
        }
        
    }
    
    double findMedian() {
        return median;
    }
};
