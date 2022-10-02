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
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        return helper(n,k,target,dp);
    }
};