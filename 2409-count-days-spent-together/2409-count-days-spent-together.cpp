class Solution {
public:
    vector<int> monthDays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        if(leaveAlice<arriveBob||leaveBob<arriveAlice)return 0;
        
        string strt=(arriveAlice>arriveBob)?arriveAlice:arriveBob;
        string end=(leaveAlice<leaveBob)?leaveAlice:leaveBob;
        int days=0;
        int mstrt=stoi(strt.substr(0,2));
        int dstrt=stoi(strt.substr(3,2));
        
        int mend=stoi(end.substr(0,2));
        int dend=stoi(end.substr(3,2));
        
        
        for(int i=mstrt;i<mend;i++)days+=monthDays[i-1];   
        days-=dstrt-1;
        days+=dend;
        return days;
    }
};