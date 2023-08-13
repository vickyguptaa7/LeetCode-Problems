class Solution {
public:
    
    bool helper(int indx,vector<int>&nums,vector<int>&dp)
    {
        if(indx==nums.size())
            return true;
        
        if(dp[indx]!=-1)
            return dp[indx];
        
        int way=0;
        if(indx+1<nums.size()&&nums[indx]==nums[indx+1])
            way|=helper(indx+2,nums,dp);
        
        if(indx+2<nums.size()&&nums[indx]==nums[indx+1]&&nums[indx]==nums[indx+2])
            way|=helper(indx+3,nums,dp);
        
        if(indx+2<nums.size()&&nums[indx]+1==nums[indx+1]&&nums[indx]+2==nums[indx+2])
            way|=helper(indx+3,nums,dp);
        
        return dp[indx]=way;
    }   
    
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};