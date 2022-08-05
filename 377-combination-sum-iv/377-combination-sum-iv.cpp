class Solution {
public:
    int helper(int target,vector<int>&nums,int sum,vector<int>&dp)
    {
        if(sum==target)return 1;
        if(dp[sum]!=-1)return dp[sum];
        int ways=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target>=sum+nums[i])
            {
                ways+=helper(target,nums,sum+nums[i],dp);
            }
        }
        return dp[sum]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        int ans=helper(target,nums,0,dp);
        return ans;
    }
};