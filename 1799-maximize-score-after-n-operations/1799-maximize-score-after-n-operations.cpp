class Solution {
public:
    
    int helper(int strt,int visited,vector<int>&nums,vector<int>&dp)
    {
        if(strt==nums.size())
            return 0;
        
        int mx=0;
        if(dp[visited]!=-1)
            return dp[visited];

        for(int i=0;i<nums.size();i++)
        {
            if(visited&(1<<i))continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(visited&(1<<j))continue;
                mx=max(mx,(strt+1)*__gcd(nums[i],nums[j])+
                       helper(strt+1,(visited|(1<<i)|(1<<j)),nums,dp));
            }
        }
        return dp[visited]=mx;
    }
    
    int maxScore(vector<int>& nums) {
        int visited=0;
        vector<int>dp(1<<14,-1);
        return helper(0,visited,nums,dp);
    }
};