class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n<=1)
            return 1;
        if(n==2)
            return 2;
        if(dp[n]!=-1)
            return dp[n];
        int ways=0;
        for(int i=1;i<=n;i++)
        {
            ways+=helper(i-1,dp)*helper(n-i,dp);
        }
        return dp[n]=ways;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};