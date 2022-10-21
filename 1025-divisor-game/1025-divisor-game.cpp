class Solution {
public:
    int helper(int n,bool isAlice,vector<int>&dp)
    {
        if(n==1||n==0)
        {
            return !isAlice;
        }
        if(dp[n]!=-1)
            return dp[n];
        if(isAlice)
        {
            int ans=0;
            for(int i=1;i<n;i++)
            {
                if(n%i==0)
                    ans=ans|(helper(n-i,!isAlice,dp));

            }
            return dp[n]=ans;
        }
        else 
        {
            int ans=1;
            for(int i=1;i<n;i++)
            {
                if(n%i==0)
                    ans=ans&(helper(n-i,!isAlice,dp));
            }
            return dp[n]=ans;
        }
    }
    bool divisorGame(int n) {
        vector<int>dp(n+1,-1);
        int ans=helper(n,1,dp);
        return ans;
    }
};