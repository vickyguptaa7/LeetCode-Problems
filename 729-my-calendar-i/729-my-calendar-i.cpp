class MyCalendar {
public:
    vector<pair<int,int>>interval;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool isSame=false;
        for(int i=0;i<interval.size();i++)
        {
            if(interval[i].first>=end||interval[i].second<=start)continue;
            isSame=true;
        }
        if(!isSame)interval.push_back({start,end});
        return !isSame;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */