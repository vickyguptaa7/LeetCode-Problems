class Solution {
public:
    
    int helper(int strt,int n,int pprofit,vector<int>&group,vector<int>&profit,vector<vector<vector<int>>>&dp)
    {
        if(strt==group.size())
        {
            return pprofit<=0;
        }
        if(dp[n][pprofit][strt]!=-1)
        {
            return dp[n][pprofit][strt];
        }
        long long ways=0,mod=1e9+7;
        if(n>=group[strt])
        {
             ways+=helper(strt+1,n-group[strt],max(pprofit-profit[strt],0),group,profit,dp);
        }
        ways+=helper(strt+1,n,pprofit,group,profit,dp);
        ways%=mod;
        return dp[n][pprofit][strt]=ways;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(minProfit+1,vector<int>(profit.size()+1,-1)));
        return helper(0,n,minProfit,group,profit,dp);
    }
};