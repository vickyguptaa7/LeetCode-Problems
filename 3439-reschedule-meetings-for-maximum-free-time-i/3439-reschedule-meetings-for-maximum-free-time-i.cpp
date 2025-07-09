class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int prev=0,kMeetingDuration=0,maxGap=0;
        for(int i=0;i<startTime.size();i++)
        {
            kMeetingDuration+=(endTime[i]-startTime[i]);
            if(i+1>=k)
            {
                maxGap=max(maxGap,(i+1<startTime.size()?startTime[i+1]:eventTime)-prev-kMeetingDuration);
                prev=endTime[i-k+1];
                kMeetingDuration-=(endTime[i-k+1]-startTime[i-k+1]);
            }
        }
        return maxGap;
    }
};