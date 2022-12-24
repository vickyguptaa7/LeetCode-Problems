class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        vector<long long>dp(n,1);
        map<long long,int>mindx;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(!mindx.count(nums[i]))
                mindx[nums[i]]=i;
            if(mindx.count((long long)nums[i]*nums[i]))
                dp[i]+=dp[mindx[(long long)nums[i]*nums[i]]];
            ans=max(ans,dp[i]);
        }
        return (ans==1)?-1:ans;
    }
};