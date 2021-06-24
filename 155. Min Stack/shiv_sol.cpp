

class MinStack {
public:
    vector<pair<int,int>> st;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        int min_element;
        if(st.empty())    min_element = val;
        else    min_element = min(st.back().second, val);
        st.push_back({val,min_element});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
        
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
