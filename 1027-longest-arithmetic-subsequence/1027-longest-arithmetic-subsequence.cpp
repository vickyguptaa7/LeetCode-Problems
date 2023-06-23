class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),longest=0,mx=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(mx+2,vector<int>(2,0)));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[j]-nums[i];
                bool isNeg=diff<0;
                diff=abs(diff);
                int cnt=1;
                if(dp[j][diff][isNeg])
                    cnt=dp[j][diff][isNeg];
                dp[i][diff][isNeg]=1+cnt;
                longest=max(longest,1+cnt);
            }
        }
        return longest;
    }
};