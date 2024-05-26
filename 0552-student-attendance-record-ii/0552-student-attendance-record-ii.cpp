class Solution {
public:
    
    int helper(int indx,int acount,int lcount,int n,vector<vector<vector<int>>>&dp)
    {
        if(indx==n)
            return 1;
        
        if(dp[indx][lcount][acount]!=-1)
            return dp[indx][lcount][acount];
        
        int ans=0,mod=1e9+7;
        if(acount<1)
        {
            ans+=helper(indx+1,acount+1,0,n,dp);
            ans%=mod;
        }
        if(lcount<2)
        {
            ans+=helper(indx+1,acount,lcount+1,n,dp);
            ans%=mod;
        }
        ans+=helper(indx+1,acount,0,n,dp);
        ans%=mod;
        return dp[indx][lcount][acount]=ans;
    }
    
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4,vector<int>(2,-1)));
        return helper(0,0,0,n,dp);
    }
};