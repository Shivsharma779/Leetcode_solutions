class MyCalendar {
public:
    set<pair<int,int>> mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int s, int e) {
        if(mp.empty()){
            mp.insert({s,e});
            return true;
        }
        
        
        auto it = mp.lower_bound({s,e});
        
        // ahead exists
        if(it != mp.end()){
            int a = it->first , b = it->second;
            if(e>a) return false;
        }
        
        // past exists
        if(it != mp.begin()){
            it--;
            int a = it->first , b = it->second;
            if(b>s) return false;
        }
        
        
        // can insert
        mp.insert({s,e});
        return true;
        
    }
    
};
