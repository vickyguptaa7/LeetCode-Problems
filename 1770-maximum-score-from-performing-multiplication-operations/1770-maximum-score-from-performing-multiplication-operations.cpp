class Solution {
public:
    
    int helper(vector<int>& nums, vector<int>& multipliers,int start,int iter,int end ,vector<vector<int>>&dp)
    {
        if(iter==multipliers.size())
        {
            return 0;
        }
        if(dp[iter][start]!=-1e9)
            return dp[iter][start];
        
        dp[iter][start]=max(helper(nums,multipliers,start+1,iter+1,end,dp)+
                            nums[start]*multipliers[iter],
                            helper(nums,multipliers,start,iter+1,end-1,dp)+
                            nums[end]*multipliers[iter]);
        return dp[iter][start];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=multipliers.size();
        vector<vector<int>>dp(n,vector<int>(n,-1e9));
        return helper(nums,multipliers,0,0,nums.size()-1,dp);
    }
};