class TimeMap {
public:
    map<string,set<int>>keyTime;
    map<int,map<string,string>>timeKeyValue;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTime[key].insert(timestamp);
        timeKeyValue[timestamp][key]=value;
    }
    
    string get(string key, int timestamp) {
        auto time=keyTime[key].upper_bound(timestamp);
        if(time==keyTime[key].begin())
        {
           
            return "";
        }
        time=prev(time);
        return timeKeyValue[*time][key];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */