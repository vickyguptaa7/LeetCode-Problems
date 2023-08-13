class Solution {
    long long dp[301][301];
public:
    
    int helper(int start,int end,vector<int>&nums)
    {
        if(start>end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        for(int i=start;i<=end;i++)
        {
            dp[start][end]=max(dp[start][end],helper(start,i-1,nums)
                               +helper(i+1,end,nums)+
                               nums[start-1]*1ll*nums[i]*1ll*nums[end+1]);
        }
        
        return dp[start][end];
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(1,(int)nums.size()-2,nums);
    }
};