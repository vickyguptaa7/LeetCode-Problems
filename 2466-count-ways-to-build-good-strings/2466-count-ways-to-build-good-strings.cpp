class Solution {
public:
    
    int helper(int curr,int low,int high,int zero,int one,vector<int>&dp)
    {
        if(high<curr)
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        int good=0,mod=1e9+7;
        if(curr>=low&&curr<=high)
            good++;
        return dp[curr]=(helper(curr+zero,low,high,zero,one,dp)+
            helper(curr+one,low,high,zero,one,dp)+(long long)good)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return helper(0,low,high,zero,one,dp);
    }
};