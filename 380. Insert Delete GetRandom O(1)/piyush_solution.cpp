class RandomizedSet {
public:
    //https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/85422/AC-C%2B%2B-Solution.-Unordered_map-%2B-Vector
    unordered_map<int,int> mp;
    vector<int> arr;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end())        //already present
            return false;
        
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end())      //not exist
            return false;
        
        //put last element at deleted element's place
        int val_idx = mp[val];          //index of ele to be delete
        arr[val_idx] = arr[arr.size()-1];   //store last ele at this index
        mp[arr[val_idx]] = val_idx;     //update last ele's index
        
        arr.pop_back();     //remove from array
        mp.erase(val);  //remove map entry
        
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[ rand() % arr.size() ];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
