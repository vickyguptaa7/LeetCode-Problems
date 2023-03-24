class RandomizedSet {
public:
    map<int,int>mindx;
    vector<int>arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mindx.count(val))
            return false;
        mindx[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mindx.count(val))
        {
            mindx[arr[arr.size()-1]]=mindx[val];
            swap(arr[mindx[val]],arr[(int)arr.size()-1]);
            arr.resize((int)arr.size()-1);
            mindx.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */