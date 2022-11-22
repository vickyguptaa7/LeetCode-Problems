class Solution {
public:
    int helper(int curr,int prev,int n,int oper,vector<vector<int>>&dp)
    {
        if(curr==n)
            return 0;
        if(curr>n||oper>n)
            return 1e9;
        if(dp[curr][prev]!=-1)return dp[curr][prev];
        return dp[curr][prev]=
            1+min(helper(curr+prev,prev,n,1+oper,dp),helper(curr,curr,n,1+oper,dp));
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(n==1)return 0;
        return 1+helper(1,1,n,1,dp);
    }
};