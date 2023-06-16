class RandomizedCollection {
public:
    
    map<int,set<int>>mset;
    vector<int>nums;
    int size;
    RandomizedCollection() {
        size=0;
    }
    
    bool insert(int val) {
        bool isPresent=!mset[val].empty();
        if(nums.size()==size)
            nums.push_back(val);
        else 
            nums[size]=val;
        mset[val].insert(size++);
        return !isPresent;
    }
    
    bool remove(int val) {
        if(mset[val].empty())
            return false;
        
        int indx=*mset[val].begin();
        mset[val].erase(indx);
        size--;
        if(indx==size)return true;
        nums[indx]=nums[size];
        mset[nums[size]].erase(size);
        mset[nums[size]].insert(indx);
        return true;
    }
    
    int getRandom() {
        int rindx=rand()%size;
        return nums[rindx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */