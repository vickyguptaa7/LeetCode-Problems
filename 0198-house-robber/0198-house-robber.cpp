class Solution {
public:
    int helper(int s,int n,vector<int>&nums,vector<int>&dp)
    {
        if(s>=n)
            return 0;
        if(dp[s]!=-1)return dp[s];
        return dp[s]=max(helper(s+1,n,nums,dp),helper(s+2,n,nums,dp)+nums[s]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(0,n,nums,dp);
    }
};