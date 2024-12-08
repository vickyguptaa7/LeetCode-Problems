class Solution {
public:
    
    int helper(int indx,int count,vector<vector<int>>&events,vector<vector<int>>&dp)
    {
        if(indx==events.size()||count==2)
            return 0;
        
        if(dp[indx][count]!=-1)
            return dp[indx][count];
        
        int ans=helper(indx+1,count,events,dp);
        ans=max(ans,helper(events[indx][3],count+1,events,dp)+events[indx][2]);
        return dp[indx][count]=ans;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        for(int i=0;i<events.size();i++)
        {
            vector<int>find={events[i][1],INT_MAX,INT_MAX};
            int nindx=lower_bound(events.begin(),events.end(),find)-events.begin();
            events[i].push_back(nindx);
        }
        vector<vector<int>>dp(events.size(),(vector<int>(2,-1)));
        return helper(0,0,events,dp);
    }
};