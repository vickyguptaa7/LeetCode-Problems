class Solution {
public:
    
    int helper(int it,int cnt,string &s,int k,vector<vector<int>>&dp)
    {
        if(s.size()<=it)
        {
            return 0;
        }
        if(dp[it][cnt]!=-1)return dp[it][cnt];
        if(s[it]=='0')
        {
            return dp[it][cnt]=max(helper(it+1,cnt+1,s,k,dp)+1,helper(it+1,cnt,s,k,dp));
        }
        else
        {
            int tmp=0;
            if(cnt<31&&k-(1<<cnt)>=0)
            {
                tmp=helper(it+1,cnt+1,s,k-(1<<cnt),dp)+1;
            }
            return dp[it][cnt]=max(tmp,helper(it+1,cnt,s,k,dp));
        }
    }
    
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        int ans=helper(0,0,s,k,dp);
        return ans;
    }
};