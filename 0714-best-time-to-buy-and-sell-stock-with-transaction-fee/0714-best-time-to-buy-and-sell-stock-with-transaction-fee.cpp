class Solution {
public:
    
    int helper(int indx,int isBuy,vector<int>&prices,int fee,vector<vector<int>>&dp)
    {
        if(indx==prices.size())
        {
            return 0;
        }
        if(dp[indx][isBuy]!=-1)
            return dp[indx][isBuy];
        
        if(isBuy)
        {
            return dp[indx][isBuy]=max(helper(indx+1,isBuy,prices,fee,dp),
                                      helper(indx+1,!isBuy,prices,fee,dp)+prices[indx]);
        }
        else 
        {
            return dp[indx][isBuy]=max(helper(indx+1,isBuy,prices,fee,dp),
                                      helper(indx+1,!isBuy,prices,fee,dp)-prices[indx]-fee);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,0,prices,fee,dp);
    }
};