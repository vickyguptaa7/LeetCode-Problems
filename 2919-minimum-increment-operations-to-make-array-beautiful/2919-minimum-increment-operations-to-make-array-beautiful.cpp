class Solution {
public:
    
    long long helper(int indx,int skip,int k,vector<int>&nums,vector<vector<long long>>&dp)
    {
        if(indx==nums.size())
            return 0;
        
        if(dp[indx][skip]!=-1)
            return dp[indx][skip];
        
        long long minmove=1e18;
        if(skip)
        {
            minmove=min(minmove,helper(indx+1,skip-1,k,nums,dp));            
        }
        
        int oper=(k-nums[indx])>0?k-nums[indx]:0;
        minmove=min(minmove,helper(indx+1,2,k,nums,dp)+oper);

        return dp[indx][skip]=minmove;
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(3,-1));
        return helper(0,2,k,nums,dp);
    }
};