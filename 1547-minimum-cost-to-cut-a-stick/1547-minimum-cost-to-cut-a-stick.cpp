class Solution {
public:
    
    int helper(int strt,int end,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(strt+1>=end)
            return 0;
        if(dp[strt][end]!=-1)
            return dp[strt][end];
        int cost=1e9;
        for(int i=strt+1;i<end;i++)
        {
            cost=min(cost,helper(strt,i,cuts,dp)+
                     helper(i,end,cuts,dp)+cuts[end]-cuts[strt]);
        }
        return dp[strt][end]=cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size()+1,-1));
        return helper(0,(int)cuts.size()-1,cuts,dp);
    }
};