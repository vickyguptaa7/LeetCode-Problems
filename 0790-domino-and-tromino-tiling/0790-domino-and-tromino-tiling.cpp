class Solution {
public:
    
    int helper(int x,bool isTromino,int n,vector<vector<int>>&dp)
    {
        if(x>=n)
        {
            if(x==n&&!isTromino)
                return 1;
            return 0;
        }
        
        if(dp[x][isTromino]!=-1)
            return dp[x][isTromino];
        
        int mod=1e9+7;
        
        if(isTromino)
        {
            return dp[x][isTromino]=((long long)helper(x+1,1,n,dp)+
                                     helper(x+2,0,n,dp))%mod;
        }
        else 
        {
            return dp[x][isTromino]=(helper(x+1,0,n,dp)+helper(x+2,0,n,dp)+
                                     2ll*helper(x+1,1,n,dp))%mod;
        }
    }
    int numTilings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,0,n,dp);
    }
};