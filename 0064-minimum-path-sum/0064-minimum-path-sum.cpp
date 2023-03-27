class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        // dp initialzed
        for(int i=0;i<n;i++)dp[i][m]=1e9;
        for(int i=0;i<m;i++)dp[n][i]=1e9;
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1&&j==m-1)
                {
                    // for the bottom right cost will be included in path
                    dp[n-1][m-1]=grid[n-1][m-1];
                }
                else 
                    dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};