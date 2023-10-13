class Solution {
public:
    
    int helper(int indx,vector<int>&cost,vector<int>&dp)
    {
        if(indx>=cost.size())
            return 0;
        
        if(dp[indx]!=-1)
            return dp[indx];
        
        return dp[indx]=cost[indx]+min(helper(indx+1,cost,dp),helper(indx+2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size();
        vector<int>dp(size,-1);
        return min(helper(1,cost,dp),helper(0,cost,dp));
    }
};