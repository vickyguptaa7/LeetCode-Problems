
bool mycomp(vector<int>&a,vector<int>&b)
{
    if(a[0]!=b[0])
        return a[0]<b[0];
    else if(a[1]!=b[1])
        return a[1]<b[1];
    return a[2]<b[2];
}

class Solution {
public:
    
    int helper(int s,vector<int>&startTime,vector<vector<int>>&time,vector<int>&dp)
    {
        if(s==time.size())
            return 0;
        
        if(dp[s]!=-1)
            return dp[s];
        
        int indx=lower_bound(startTime.begin(),startTime.end(),
                             time[s][1])-startTime.begin();
        
        return dp[s]=max(helper(indx,startTime,time,dp)+time[s][2],
                         helper(s+1,startTime,time,dp));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n=startTime.size();
        vector<vector<int>>time;
        for(int i=0;i<n;i++)
        {
            time.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(time.begin(),time.end(),mycomp);
        sort(startTime.begin(),startTime.end());

        vector<int>dp(n+1,-1);
        return helper(0,startTime,time,dp);
    }
};