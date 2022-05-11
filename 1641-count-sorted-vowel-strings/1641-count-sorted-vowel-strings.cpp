class Solution {
public:
    vector<char>vowel={'a','e','i','o','u'};
    int countVowelStrings(int n) {
        int res=0;
        string str;
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        return helper(n,0,dp);
    }
    int helper(int n,int prev,vector<vector<int>>&dp)
    {
        if(n<=0)
        {
           return 1;
        }
        if(dp[n][prev]!=-1)return dp[n][prev];
        
        int sum=0;
        for(int i=prev;i<5;i++)
        {
            sum+=helper(n-1,i,dp);    
        }
        return dp[n][prev]=sum;
    }
};