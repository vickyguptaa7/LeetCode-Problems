class Solution {
    
    int dp[1000][101][2];
    
    int helper(int indx,int k,bool isBuy,vector<int>&prices)
    {
        if(indx==prices.size()||k<0)
            return 0;
        
        if(dp[indx][k][isBuy]!=-1)
            return dp[indx][k][isBuy];
        
        if(isBuy)
        {
            return dp[indx][k][isBuy]=max(helper(indx+1,k,isBuy,prices),
                                         helper(indx+1,k-1,!isBuy,prices)-prices[indx]
                                         );
        }
        else
        {
            return dp[indx][k][isBuy]=max(helper(indx+1,k,isBuy,prices),
                                         helper(indx+1,k,!isBuy,prices)+prices[indx]
                                         );
        }
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return helper(0,k,1,prices);
    }
};