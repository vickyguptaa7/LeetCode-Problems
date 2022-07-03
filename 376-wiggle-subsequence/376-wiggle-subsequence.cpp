class Solution {
public:
    int helper(int curr,int prev,bool isGreat,vector<int>&nums,vector<vector<vector<int>>>&dp)
    {
        if(curr>=nums.size())return 1;
        
        if(dp[curr][prev+1][isGreat]!=-1)return dp[curr][prev+1][isGreat];
        
        if(prev!=-1&&isGreat&&nums[curr]>nums[prev])
        {
            dp[curr][prev+1][isGreat]=max(1+helper(curr+1,curr,!isGreat,nums,dp),
                                          helper(curr+1,prev,isGreat,nums,dp));
        }
        else if(prev!=-1&&!isGreat&&nums[curr]<nums[prev])
        {
            dp[curr][prev+1][isGreat]=max(1+helper(curr+1,curr,!isGreat,nums,dp),
                                          helper(curr+1,prev,isGreat,nums,dp));
        }
        else
        {
            dp[curr][prev+1][isGreat]=max(helper(curr+1,curr,isGreat,nums,dp),
                                          helper(curr+1,prev,isGreat,nums,dp));
        }
        return dp[curr][prev+1][isGreat];
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return max(helper(0,-1,false,nums,dp),helper(0,-1,true,nums,dp));
    }
};