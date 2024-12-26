class Solution {
public:
    
    int helper(int lvl,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(lvl==nums.size())
            return target==0;
        
        if(dp[lvl][target+25000]!=-1)
            return dp[lvl][target+25000];
        
        return dp[lvl][target+25000]=helper(lvl+1,target+nums[lvl],nums,dp)+helper(lvl+1,target-nums[lvl],nums,dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(50000,-1));
        return helper(0,target,nums,dp);
    }
};