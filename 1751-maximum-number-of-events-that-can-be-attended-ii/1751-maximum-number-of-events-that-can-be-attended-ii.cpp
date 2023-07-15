bool mycomp(vector<int>&a,vector<int>&b)
{
    return (a[0]<b[0]);
}

class Solution {
public:
    
    int helper(int indx,int k,vector<vector<int>>&events,vector<vector<int>>&dp)
    {
        if(indx>=events.size())
            return 0;
        if(!k)
            return 0;
        
        if(dp[indx][k]!=-1)
            return dp[indx][k];
        
        int mxVal=helper(indx+1,k,events,dp);
        vector<int>temp={events[indx][1],INT_MAX,INT_MAX};
        
        int nindx=upper_bound(events.begin(),events.end(),temp)-events.begin();
        
        mxVal=max(mxVal,events[indx][2]+helper(nindx,k-1,events,dp));
        
        return dp[indx][k]=mxVal;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end(),mycomp);
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return helper(0,k,events,dp);
    }
};