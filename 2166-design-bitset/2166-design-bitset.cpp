class Bitset {
public:
    vector<bool>bitsset,flipset;
    int setCnt=0;
    bool isFlipped;
    Bitset(int size) {
        bitsset.resize(size,0);
        flipset.resize(size,1);
        isFlipped=false;
    }
    
    void fix(int idx) {
        if(!bitsset[idx])
        {
            setCnt++;
            bitsset[idx]=true;
            flipset[idx]=false;
        }
    }
    
    void unfix(int idx) {
        if(bitsset[idx])
        {
            setCnt--;
            bitsset[idx]=false;
            flipset[idx]=true;
        }
    }
    
    void flip() {
        isFlipped=!isFlipped;
        int size=bitsset.size();
        setCnt=size-setCnt;
        swap(bitsset,flipset);
    }
    
    bool all() {
        return setCnt==bitsset.size();
    }
    
    bool one() {
        return setCnt>0;
    }
    
    int count() {
        return setCnt;
    }
    
    string toString() {
        string bits;
        for(int i=0;i<bitsset.size();i++)
        {
            bits+=(bitsset[i]+'0');
        }
        return bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */