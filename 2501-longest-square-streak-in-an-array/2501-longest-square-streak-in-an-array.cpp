class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        unordered_map<long long,int>dp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[nums[i]]=1+dp[nums[i]*1ll*nums[i]];
            ans=max(ans,dp[nums[i]]);
        }
        return ans<2?-1:ans;
    }
};