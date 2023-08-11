class Solution {
    int dp[300][5001];
    
    int helper(int indx,int amount,vector<int>&coins)
    {
        if(indx==coins.size()||amount==0)
            return amount==0;
        
        if(dp[indx][amount]!=-1)
            return dp[indx][amount];
        
        int ways=helper(indx+1,amount,coins);
        if(amount>=coins[indx])
            ways+=helper(indx,amount-coins[indx],coins);
        
        return dp[indx][amount]=ways;
    }
    
public:
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return helper(0,amount,coins);
    }
};