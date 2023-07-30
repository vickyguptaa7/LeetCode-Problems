class Solution {
public:
    
    int helper(int sindx,int eindx,string& s,vector<vector<int>>&dp)
    {
        if(sindx>eindx)
            return 0;
        if(sindx==eindx)
            return 1;
        if(eindx-sindx==1&&s[sindx]==s[eindx])
            return 1;
        if(eindx-sindx==1&&s[sindx]!=s[eindx])
            return 2;
        
        if(dp[sindx][eindx]!=-1)
            return dp[sindx][eindx];
        
        int cost=1e9;
        bool isSame=s[sindx]==s[eindx];
        for(int i=sindx;i<eindx;i++)
        {
            cost=min(cost,helper(sindx,i,s,dp)+helper(i+1,eindx,s,dp)-isSame);
        }
        return dp[sindx][eindx]=cost;
    }
    
    int strangePrinter(string s) {
        string ns;
        ns+=s[0];
        for(int i=1;i<s.size();i++)
            if(ns.back()!=s[i])
                ns+=s[i];
        vector<vector<int>>dp(ns.size(),vector<int>(ns.size(),-1));
        return helper(0,(int)ns.size()-1,ns,dp);
    }
};