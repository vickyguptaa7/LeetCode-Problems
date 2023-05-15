class Solution {
public:
    
    long long helper(int strt,int k,vector<int>&nums,vector<vector<long long>>&dp)
    {
        if(nums.size()==strt)
            return 0;
        if(dp[strt][k]!=-1)
            return dp[strt][k];
        long long maxOrVal=nums[strt]|(helper(strt+1,k,nums,dp));
        for(int i=1;i<=k;i++)
        {
            maxOrVal=max(maxOrVal,(nums[strt]*(1ll<<i))|helper(strt+1,k-i,nums,dp));
        }
        return dp[strt][k]=maxOrVal;
    }
    
    long long maximumOr(vector<int>& nums, int k) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(k+1,-1));
        return helper(0,k,nums,dp);
    }
};