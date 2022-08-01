class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][m-1]=1;
        }
        for(int i=0;i<=m;i++)
        {
            dp[n-1][i]=1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0]/2;
    }
};