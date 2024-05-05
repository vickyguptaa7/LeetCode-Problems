class Solution {
    long long dp[1001][1001];
public:
    
    int helper(int n,int k)
    {
        if(n==0)
            return dp[n][k]=0;
        
        if(k==0)
            return dp[n][k]=1;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=0,mod=1e9+7;
        for(int i=0;i<n&&k>=i;i++)
        {
            ans+=helper(n-1,k-i);
            ans%=mod;
        }
        return dp[n][k]=ans;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                if(j>=i)
                {
                    dp[i][j]-=dp[i-1][j-i]+0ll-mod;
                    dp[i][j]%=mod;
                }
            }
        }
        return dp[n][k];
    }
};