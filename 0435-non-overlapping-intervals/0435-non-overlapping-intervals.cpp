bool comp(vector<int>&a,vector<int>&b)
{
    return a[0]<b[0];
}

class Solution {
public:
    
    int helper(int indx,vector<vector<int>>&intervals,vector<int>&dp)
    {
        if(indx==intervals.size())
            return 0;
        if(dp[indx]!=-1)
            return dp[indx];
        int minRemove=1+helper(indx+1,intervals,dp);
        vector<int>temp={intervals[indx][1],INT_MIN};
        int nindx=lower_bound(intervals.begin(),intervals.end(),temp)-
            intervals.begin();
        return dp[indx]=min(minRemove,nindx-indx-1+helper(nindx,intervals,dp));
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>dp(intervals.size(),-1);
        return helper(0,intervals,dp);
    }
};