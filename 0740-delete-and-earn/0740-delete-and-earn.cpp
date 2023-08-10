class Solution {
    int dp[20001],preSum[20001];
public:
    
    int helper(int indx,vector<int>&nums)
    {
        if(indx>=nums.size())
            return 0;
        
        if(dp[indx]!=-1)
            return dp[indx];
        
        int nindx=upper_bound(nums.begin(),nums.end(),nums[indx])-nums.begin();
        int mxEarn=helper(nindx,nums);
        int sum=preSum[nindx]-preSum[indx];
        nindx=upper_bound(nums.begin(),nums.end(),nums[indx]+1)-nums.begin();
        mxEarn=max(mxEarn,sum+helper(nindx,nums));
        
        return dp[indx]=mxEarn;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(preSum,0,sizeof(preSum));
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++)preSum[i]+=preSum[i-1]+nums[i-1];
        return helper(0,nums);
    }
};