class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string r=s;
        reverse(r.begin(),r.end());
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(r[i-1]==s[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};