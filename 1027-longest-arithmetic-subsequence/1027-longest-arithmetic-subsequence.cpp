class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),longest=0;
        vector<vector<int>>dp(n+1,vector<int>(1004,0));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[j]-nums[i]+502;
                bool isNeg=diff<0;
                diff=abs(diff);
                int cnt=1;
                if(dp[j][diff])
                    cnt=dp[j][diff];
                dp[i][diff]=1+cnt;
                longest=max(longest,1+cnt);
            }
        }
        return longest;
    }
};