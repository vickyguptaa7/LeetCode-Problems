class MyCalendar {
    map<int,int>calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=calendar.upper_bound(start);
        if(it!=calendar.end()&&it->second<end)
        {
            return false;
        }
        calendar[end]=start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */