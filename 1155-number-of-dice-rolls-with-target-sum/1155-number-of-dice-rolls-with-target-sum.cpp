class Solution {
public:
    int helper(int n,int k,int target,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(target==0)return 1;
            return 0;
        }
        if(target<=0)
            return 0;
        
        if(dp[target][n]!=-1)
            return dp[target][n];
        
        long long ways=0,mod=1e9+7;
        for(int i=1;i<=k;i++)
        {
            ways+=helper(n-1,k,target-i,dp);
            ways%=mod;
        }
        return dp[target][n]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(target+1,vector<int>(n+1,0));
        dp[0][0]=1;
        int mod=1e9+7;
        for(int i=1;i<=target;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int l=1;l<=k;l++)
                {
                    if(l>i)
                        continue;
                    dp[i][j]+=dp[i-l][j-1];
                    dp[i][j]%=mod;
                }
            }
        }
        return dp[target][n];
    }
};