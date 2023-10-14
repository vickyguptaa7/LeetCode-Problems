class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end(),greater<int>());
        sort(processorTime.begin(),processorTime.end());
        int time=0;
        for(int i=0;i<tasks.size();i++)
        {
            int currTime=tasks[i]+processorTime[i/4];
            time=max(time,currTime);
        }
        return time;
    }
};