class Solution {
public:
    int helper(int startPos,int endPos,int k,vector<vector<int>>&dp)
    {
        if(abs(startPos-endPos)>k)
            return 0;
        
        if(k==0)
            return startPos==endPos;
        
        if(dp[startPos+1305][k]!=-1)
            return dp[startPos+1305][k];
        
        long long ways=0,mod=1e9+7;
        ways+=helper(startPos+1,endPos,k-1,dp);
        ways%=mod;
        ways+=helper(startPos-1,endPos,k-1,dp);
        ways%=mod;
        
        return dp[1305+startPos][k]=ways;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        if(abs(startPos-endPos)%2!=k%2)
            return 0;
        vector<vector<int>>dp(3e3+10,vector<int>(k+2,-1));
        return helper(startPos,endPos,k,dp);
    }
};