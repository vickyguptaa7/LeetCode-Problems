class CountIntervals {
public:
    map<int,int>intrvl;
    int cnt;
    CountIntervals() {
        cnt=0;
    }
    
    void add(int left, int right) {
        int l=left,r=right;
        auto itr=intrvl.lower_bound(left);
        
        while(itr!=intrvl.end()&&itr->second<=right)
        {
            int smLeft=itr->second;
            int smRight=itr->first;
            cnt-=(smRight-smLeft+1);
            itr=intrvl.erase(itr);
            l=min(l,smLeft);
            r=max(r,smRight);
            // cout<<itr->first<<" "<<itr->second<<"\n";
        }
        intrvl[r]=l;
        cnt+=r-l+1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */