class LRUCache {
    int c;
    list<pair<int,int>> lru;
    //unordered_map<int,int> m;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        c = capacity;    
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        updateLRU(key , mp[key]->second);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        updateLRU(key,value);
        //mp[key] = value;
        if(mp.size() > c){
            //m.erase(lru.back());
            mp.erase(lru.back().first);
            lru.pop_back();
        }
    }
    void updateLRU(int key, int value){
        if(mp.find(key) != mp.end())
            lru.erase(mp[key]);
        lru.push_front({key,value});
        mp[key] = lru.begin();
        
        
    }
};
