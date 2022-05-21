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
        vector<vector < int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans=dfs_helper(amount, 0, coins, dp);
        return ans==1e9?-1:ans;
       	//         for(int i=0;i<n+1;i++)
       	//         {
       	//             dp[i][0]=0  ;
       	//         }
       	//         for(int i=0;i<amount+1;i++)
       	//         {

       	//         }
    }
};