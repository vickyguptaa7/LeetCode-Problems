class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+delay;j<min(n+1,i+forget);j++)
            {
                dp[j]=(dp[i]+dp[j])%mod;
            }
        }
        long long result=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            result+=dp[i];
            result%=mod;
        }
        return result;
    }
};