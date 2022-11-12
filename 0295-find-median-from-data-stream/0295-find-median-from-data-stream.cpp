class MedianFinder {
public:
    multiset<int>lset,hset;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lset.empty()||*lset.rbegin()>num)
        {
            lset.insert(num);
        }
        else 
        {
            hset.insert(num);
        }
        if(lset.size()>(hset.size()+1))
        {
            hset.insert(*lset.rbegin());
            lset.erase(lset.find(*lset.rbegin()));
        }
        else if(hset.size()>(lset.size()+1))
        {
            lset.insert(*hset.begin());
            hset.erase(hset.find(*hset.begin()));
        }
    }
    
    double findMedian() {
        if(lset.size()==hset.size())return (*lset.rbegin()+*hset.begin())/2.0;
        else if(lset.size()>hset.size())
        {
            return *lset.rbegin();
        }
        else 
        {
            return *hset.begin();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */