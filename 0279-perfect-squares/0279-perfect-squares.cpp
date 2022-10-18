class Solution {
public:
    
    int helper(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int move=1e9;
        for(int i=1;i*i<=n;i++)
        {
            move=min(move,helper(n-i*i,dp)+1);
        }
        return dp[n]=move;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};