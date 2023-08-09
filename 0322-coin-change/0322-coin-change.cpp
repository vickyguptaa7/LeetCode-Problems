class Solution {
    
    int helper(int amount,vector<int>& coins,vector<int>&dp)
    {
        if(amount==0)
            return 0;
        
        if(dp[amount]!=-1)
            return dp[amount];
        
        int minWays=1e9;
        
        for(int i=0;i<coins.size();i++)
        {
            if(amount-coins[i]>=0)
                minWays=min(minWays,1+helper(amount-coins[i],coins,dp));
        }
        
        return dp[amount]=minWays;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int coinReq=helper(amount,coins,dp);
        return coinReq>=1e9?-1:coinReq;
    }
};