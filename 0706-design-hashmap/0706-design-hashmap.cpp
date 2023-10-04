class MyHashMap {
public:
    vector<int>mp;
    MyHashMap() {
        int size=1e6+1;
        mp.resize(size,-1);
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        if(mp[key]==-1)
            return -1;
        return mp[key];
    }
    
    void remove(int key) {
        mp[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */