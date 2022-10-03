class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l=0,r=1;
        int time=0;
        while(r<colors.size())
        {
            int maxTime=neededTime[l],sum=neededTime[l];
            while(r<colors.size()&&colors[l]==colors[r])
            {
                sum+=neededTime[r];
                maxTime=max(maxTime,neededTime[r]);
                r++;
            }
            if(r-l>1)
            {
                time+=sum-maxTime;
            }
            l=r;
            r++;
        }
        return time;
    }
};