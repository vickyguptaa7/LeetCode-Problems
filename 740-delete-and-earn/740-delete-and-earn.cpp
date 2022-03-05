class Solution {
public:
    int Dp(vector<int>&freq,int s,vector<int>&dp)
    {
        if(s>=freq.size())
        {
            return 0;
        }
        if(dp[s]!=-1)
        {
            return dp[s];
        }
        
        dp[s]=max(
                Dp(freq,s+1,dp),
                Dp(freq,s+2,dp)+s*freq[s]);
        
        return dp[s];
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(10001,0);
        for(auto &x:nums)
        {
            freq[x]++;
        }
        vector<int>dp(20001,-1);

        int ans=Dp(freq,0,dp);
        return ans;
    }
};