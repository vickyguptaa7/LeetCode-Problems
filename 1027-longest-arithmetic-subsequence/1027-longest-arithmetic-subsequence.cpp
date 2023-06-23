class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),longest=0;
        unordered_map<int,int>dp[n+1];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[j]-nums[i];
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