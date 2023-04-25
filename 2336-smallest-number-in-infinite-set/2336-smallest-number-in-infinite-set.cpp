class SmallestInfiniteSet {
public:
    
    set<int>infset;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            infset.insert(i);
        }
    }
    
    int popSmallest() {
        int small=*infset.begin();
        infset.erase(small);
        return small;
    }
    
    void addBack(int num) {
        infset.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */