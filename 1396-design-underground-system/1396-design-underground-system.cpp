class UndergroundSystem {
public:
    map<int,pair<string,int>>checkIns;
    map<string,pair<int,int>>checkOuts;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string strtSName=checkIns[id].first;
        int sTime=checkIns[id].second;
        checkIns.erase(id);
        string newStr=strtSName+" "+stationName;
        int prevCnt=0,prevTime=0;
        if(checkOuts.find(newStr)!=checkOuts.end())
        {
            prevCnt+=checkOuts[newStr].second;
            prevTime+=checkOuts[newStr].first;
        }
        checkOuts[newStr]={prevTime+(t-sTime),prevCnt+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string newStr=startStation+" "+endStation;
        double cnt=checkOuts[newStr].second;
        double time=checkOuts[newStr].first;
        
        double ans=time/cnt;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */