class Solution
{
    public:

        int dfs_helper(int amount, int it, vector<int> &coins, vector<vector< int>> &dp)
        {
            if (amount == 0 || it >= coins.size())
            {
                if (amount == 0)
                    return 0;
                return 1e9;
            }

            if (dp[it][amount] != -1) return dp[it][amount];

            if (amount >= coins[it])
            {
                return dp[it][amount] = min(dfs_helper(amount - coins[it], it, coins, dp) + 1,
                    dfs_helper(amount, it + 1, coins, dp));
            }
            else
            {
                return dp[it][amount] = dfs_helper(amount, it + 1, coins, dp);
            }
        }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, 0));
        // int ans = dfs_helper(amount, 0, coins, dp);
        // return ans == 1e9 ? -1 : ans;

        for (int i = 1; i < amount + 1; i++) 
        {
            dp[0][i]=1e9;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(j>=coins[i-1])
                {
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==1e9?-1:dp[n][amount];
    }
};