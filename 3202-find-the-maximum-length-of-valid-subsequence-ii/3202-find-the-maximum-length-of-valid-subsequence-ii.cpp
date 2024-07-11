class Solution {
public:
    
    int helper(int prev,int indx,int k,vector<int>&nums,map<int,vector<int>>&mp,vector<vector<int>>&dp)
    {
        if(dp[prev][indx]!=-1)
            return dp[prev][indx];
        
        int ans=2;
        auto cindx=lower_bound(mp[nums[prev]%k].begin(),mp[nums[prev]%k].end(),indx);
        if(cindx!=mp[nums[prev]%k].begin())
        {
            cindx--;
            ans=max(ans,1+helper(indx,*cindx,k,nums,mp,dp));
        }
        return dp[prev][indx]=ans;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int,vector<int>>mp;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]%k].push_back(i);
        }
        
        int ans=2;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                ans=max(ans,helper(j,i,k,nums,mp,dp)-1);
            }
        }
        return ans;
    }
};