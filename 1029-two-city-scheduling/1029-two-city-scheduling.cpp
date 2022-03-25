class Solution {
public:
    
    int helper(vector<vector<int>>&costs,int s,int n,int m,vector<vector<int>>&dp)
    {
        if(n>costs.size()||m>costs.size())
        {
            return 1e9;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s==costs.size())
        {
            if(n==m)
            {
                return 0;
            }
            else
            {
                return 1e9;
            }
        }
        
        return dp[n][m]=min(helper(costs,s+1,n+1,m,dp)+costs[s][0],helper(costs,s+1,n,m+1,dp)+costs[s][1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(costs,0,0,0,dp);
    }
};