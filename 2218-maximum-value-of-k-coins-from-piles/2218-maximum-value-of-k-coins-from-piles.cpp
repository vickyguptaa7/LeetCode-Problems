class Solution {
public:
    
    int helper(int src,int cntr,int k,vector<vector<int>>&piles,vector<vector<int>>&dp)
    {
        if(src==piles.size()||cntr==k)
            return 0;
        if(dp[src][cntr]!=-1)
            return dp[src][cntr];
        int cost=0,profit=helper(src+1,cntr,k,piles,dp);
        for(int i=0;i<piles[src].size()&&cntr+i+1<=k;i++)
        {
            cost+=piles[src][i];
            profit=max(profit,cost+helper(src+1,cntr+i+1,k,piles,dp));
        }
        return dp[src][cntr]=profit;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(k+1,-1));
        return helper(0,0,k,piles,dp);
    }
};