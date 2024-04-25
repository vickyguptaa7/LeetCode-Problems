class Solution {
public:
    
    int helper(int indx,int prev,int k,string &s,vector<vector<int>>&dp)
    {
        if(indx==s.size())
            return 0;
        
        if(dp[indx][prev+1]!=-1)
            return dp[indx][prev+1];
        
        int mx=0;
        if(prev==-1||abs((s[indx]-'a')-prev)<=k)
        {
            mx=helper(indx+1,s[indx]-'a',k,s,dp)+1;
        }
        
        mx=max(mx,helper(indx+1,prev,k,s,dp));
        
        return dp[indx][prev+1]=mx;
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size(),vector<int>(27,-1));
        return helper(0,-1,k,s,dp);
    }
};