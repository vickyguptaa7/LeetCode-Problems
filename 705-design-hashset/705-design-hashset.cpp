class MyHashSet {
public:
    bool *freq;
    MyHashSet() {
        freq=new bool[1e6+1];
        for(int i=0;i<1e6+1;i++)freq[i]=false;
    }
    
    void add(int key) {
        freq[key]=true;
    }
    
    void remove(int key) {
        freq[key]=false;
    }
    
    bool contains(int key) {
        if(freq[key]==false)return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */