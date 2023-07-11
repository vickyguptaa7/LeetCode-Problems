class Solution {
public:
    
    int helper(int sindx,int tindx,string &s,string &t,vector<vector<int>>&dp)
    {
        if(sindx==s.size()||tindx==t.size())
        {
            return tindx==t.size();
        }
        if(dp[sindx][tindx]!=-1)
            return dp[sindx][tindx];
        dp[sindx][tindx]=helper(sindx+1,tindx,s,t,dp);
        if(s[sindx]==t[tindx])
            return dp[sindx][tindx]+=helper(sindx+1,tindx+1,s,t,dp);
        return dp[sindx][tindx];
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return helper(0,0,s,t,dp);
    }
};