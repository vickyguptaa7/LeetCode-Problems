class Solution {
public:

    int helper(int lvl,int cnt,string& s,int k,vector<vector<int>>&dp)
    {
        if(s.size()<=lvl) {
            return 0;
        }
        if(dp[lvl][cnt]!=-1) {
            return dp[lvl][cnt];
        }
        if(s[lvl]=='0') {
            return dp[lvl][cnt]=max(helper(lvl+1,cnt,s,k,dp),1+helper(lvl+1,cnt+1,s,k,dp));
        }
        else {
            int tmp=0;
            if(cnt<31&&k-(1<<cnt)>=0) {
                tmp=helper(lvl+1,cnt+1,s,k-(1<<cnt),dp)+1;
            }
            return dp[lvl][cnt]=max(tmp,helper(lvl+1,cnt,s,k,dp));
        }
    }

    int longestSubsequence(string s, int k) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        reverse(s.begin(),s.end());
        return helper(0,0,s,k,dp);
    }
};