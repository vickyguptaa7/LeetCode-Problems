class Solution {
public:
    
    int helper(int s,vector<int>&cost,vector<int>&dp)
    {
        if(s>=cost.size())return 0;
        
        if(dp[s]!=-1)return dp[s];
        
        dp[s]=cost[s]+min(helper(s+1,cost,dp),helper(s+2,cost,dp));
        return dp[s];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(helper(0,cost,dp),helper(1,cost,dp));
        return ans;
    }
};