class Solution {
public:

    bool helper(int lvl,int tar,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(tar==0)
            return true;

        if(lvl==nums.size())
            return 0;
        
        if(dp[lvl][tar]!=-1)
        {
            return dp[lvl][tar];
        }

        if(tar>=nums[lvl])
        {
            return dp[lvl][tar]=(helper(lvl+1,tar,nums,dp)|helper(lvl+1,tar-nums[lvl],nums,dp));
        }
        else
        {
            return dp[lvl][tar]=helper(lvl+1,tar,nums,dp);
        }
    }

    bool canPartition(vector<int>& nums) {
        int target=accumulate(nums.begin(),nums.end(),0ll);
        if(target&1)
            return false;
        vector<vector<int>>dp(nums.size(),vector<int>(20000,-1));
        return helper(0,target/2,nums,dp);
    }
};