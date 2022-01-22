class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int k=1;k*k<=i;k++)
            {
                int temp=k*k;
                if(dp[i-temp]==0)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};