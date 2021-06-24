class LRUCache {
public:
    //stores only key
    list<short> q;
    
    //key , iterator for queue , value
    unordered_map<short,pair<list<short>::iterator , short>> mp;
    short cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        q.erase(mp[key].first);         //erase key at given iterator
        q.push_front(key);              //push key to front
        mp[key].first = q.begin();
        
        return mp[key].second;          //return value
    }
    
    void put(int key, int value) {
        q.push_front(key);              //move/add key to front
                
        if(mp.find(key)==mp.end())      //key doesn't exist already           
            cap--;
        else
            q.erase(mp[key].first);     //erase old iterator
        
        mp[key] = {q.begin() , value};
        
        
        if(cap<0)       //overflow
        {
            mp.erase(q.back());     //remove entry from map
            q.pop_back();
            cap++;
        }
        
    }
};
