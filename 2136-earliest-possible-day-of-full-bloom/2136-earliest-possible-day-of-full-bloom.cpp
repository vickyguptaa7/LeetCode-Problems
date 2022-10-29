bool mycomp(pair<int,int>&a,pair<int,int>&b)
{
    return a.second>b.second;
}
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>pgTime;
        for(int i=0;i<growTime.size();i++)
        {
            pgTime.push_back({plantTime[i],growTime[i]});
        }
        sort(pgTime.begin(),pgTime.end(),mycomp);
        int maxTime=0,currTime=0;
        for(auto [pt,gt]:pgTime)
        {
            maxTime=max(maxTime,currTime+pt+gt);
            currTime+=pt;
        }
        return maxTime;
    }
};