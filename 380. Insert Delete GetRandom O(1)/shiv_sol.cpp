class RandomizedSet {
public:
    unordered_map<int,int> s;
    vector<int> v;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s.find(val) != s.end()) return false;
        s.insert({val,v.size()});
        
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) == s.end()) return false;
        // for(auto x : v) cout << x << " ";
        
        int i = s[val];
        s[v[v.size()-1]] = i;
        swap(v[i],v[v.size()-1]);
        v.pop_back();
        s.erase(val);
        // for(auto x : v) cout << x << " ";
        // cout << endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
