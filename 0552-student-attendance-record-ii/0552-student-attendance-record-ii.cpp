class Solution {
    int dp[100005][3][2];
public:
    
    int helper(int indx,int acount,int lcount,int n)
    {
        if(indx==n)
            return 1;
        
        if(dp[indx][lcount][acount]!=-1)
            return dp[indx][lcount][acount];
        
        int ans=0,mod=1e9+7;
        if(acount<1)
        {
            ans+=helper(indx+1,acount+1,0,n);
            ans%=mod;
        }
        if(lcount<2)
        {
            ans+=helper(indx+1,acount,lcount+1,n);
            ans%=mod;
        }
        ans+=helper(indx+1,acount,0,n);
        ans%=mod;
        return dp[indx][lcount][acount]=ans;
    }
    
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,n);
    }
};