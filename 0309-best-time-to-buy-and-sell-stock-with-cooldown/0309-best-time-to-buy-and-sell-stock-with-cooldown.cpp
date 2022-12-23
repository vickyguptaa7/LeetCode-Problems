class Solution {
public:
    
    int helper(int s,bool isSell,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(s>=prices.size())
            return 0;

        if(dp[s][isSell]!=-1)
            return dp[s][isSell];
        
        if(isSell)
        {
            return dp[s][isSell]=max(helper(s+2,0,prices,dp)+prices[s],
                                    helper(s+1,1,prices,dp));
        }
        else 
        {
            return dp[s][isSell]=max(helper(s+1,1,prices,dp)-prices[s],
                                    helper(s+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,0,prices,dp);
    }
};