class Solution {
public:
    
    
    int helper(int iter,int k,int isBuy,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(iter==prices.size()||k==0)return 0;
        if(dp[iter][k][isBuy]!=-1)return dp[iter][k][isBuy];
        
        int profit=0;
        if(isBuy)
        {
            int buy=helper(iter+1,k,!isBuy,prices,dp)-prices[iter];
            int dontBuy=helper(iter+1,k,isBuy,prices,dp);
            profit=max(buy,dontBuy);
        }
        else 
        {
            int sell=helper(iter+1,k-1,!isBuy,prices,dp)+prices[iter];
            int dontSell=helper(iter+1,k,isBuy,prices,dp);
            profit=max(sell,dontSell);
        }
        return dp[iter][k][isBuy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        
        return helper(0,k,1,prices,dp);
    }
};