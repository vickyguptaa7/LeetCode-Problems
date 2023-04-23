class Solution {
public:
    
    int helper(int strt,string &s,int k,vector<int>&dp)
    {
        if(strt==s.size())
            return 1;
        if(s[strt]=='0')
            return 0;
        if(dp[strt]!=-1)
            return dp[strt];
        
        long long num=0,ways=0,mod=1e9+7;
        for(int i=strt;i<s.size();i++)
        {
            num=num*10+(s[i]-'0');
            if(num>k)
                break;
            ways+=helper(i+1,s,k,dp);
            ways%=mod;
        }
        return dp[strt]=ways;
    }
    
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(),-1);
        return helper(0,s,k,dp);
    }
};