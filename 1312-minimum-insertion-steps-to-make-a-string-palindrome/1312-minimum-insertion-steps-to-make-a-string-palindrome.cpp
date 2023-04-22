class Solution {
public:
    
    int helper(int left,int right,string &s,vector<vector<int>>&dp)
    {
        if(left>=right)
            return 0;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        if(s[left]==s[right])
        {
            return dp[left][right]=helper(left+1,right-1,s,dp);
        }
        
        return dp[left][right]=1+min(helper(left+1,right,s,dp),helper(left,right-1,s,dp));
    }
    
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};