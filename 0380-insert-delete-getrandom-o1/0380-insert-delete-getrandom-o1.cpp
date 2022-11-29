class RandomizedSet {
public:
    map<int,int>valIndx;
    vector<int>value;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valIndx.count(val))
            return false;
        valIndx[val]=value.size();
        value.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!valIndx.count(val))
            return false;
        int last=value.back();
        int pop=valIndx[val];
        
        value[pop]=last;
        valIndx[last]=pop;
        value.pop_back();
        valIndx.erase(val);
        return true;
    }
    
    int getRandom() {
        return value[rand()%value.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */