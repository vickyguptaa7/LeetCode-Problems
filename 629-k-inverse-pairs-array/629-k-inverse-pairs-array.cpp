class Solution {
public:
    
    int helper(int n,int k,vector<vector<int>>&dp)
    {
        if(n==0)
            return dp[n][k]=0;
        
        if(k==0)
            return dp[n][k]=1;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        long long ans=0;
        for(int i=0;i<=min(k,n-1);i++)
        {
            ans+=helper(n-1,k-i,dp);
            int mod=1e9+7;
            ans%=mod;
        }
        return dp[n][k]=ans;
        
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        int mod=1e9+7;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=mod;
                if(j>=i)
                {
                    dp[i][j]-=dp[i-1][j-i];
                    dp[i][j]+=mod;
                    dp[i][j]%=mod;
                }
            }
        }
        return dp[n][k];
    }
};