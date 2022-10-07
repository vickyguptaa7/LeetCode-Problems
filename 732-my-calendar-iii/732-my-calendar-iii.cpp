class MyCalendarThree {
public:
    map<int,int>interval;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        interval[start]++;
        interval[end]--;
        int maxOverlap=0,overlap=0;
        for(auto x:interval)
        {
            overlap+=x.second;
            maxOverlap=max(maxOverlap,overlap);
        }
        return maxOverlap;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */