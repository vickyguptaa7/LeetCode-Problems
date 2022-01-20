class Solution {
public:
    bool canWinNim(int n) {
        if(n>1e6)
        {
            bool ans=(n%4)==0;
            return (!ans);
        }
        vector<bool>dp(n);
        dp[0]=1;
        dp[1]=1;
        dp[2]=1;
        dp[3]=0;
        for(int i=4;i<=n;i++)
        {
            int isWin=0;
            for(int j=1;j<=3;j++)
            {
                if(dp[i-j-1]==0)
                {
                    isWin=true;
                    break;
                }
            }
            dp[i-1]=isWin;
        }
        return dp[n-1];
    }
};