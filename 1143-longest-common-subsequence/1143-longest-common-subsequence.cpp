class Solution {
public:
    
    int helper(int it1,int it2,int l1,int l2,string &text1,string &text2,
               vector<vector<int>>&dp)
    {
        if(it1==l1||it2==l2)
            return 0;
        if(dp[it1][it2]!=-1)
            return dp[it1][it2];
        
        if(text1[it1]==text2[it2])
        {
            return dp[it1][it2]=1+helper(it1+1,it2+1,l1,l2,text1,text2,dp);
        }
        else 
            return dp[it1][it2]=max(helper(it1+1,it2,l1,l2,text1,text2,dp),
                                   helper(it1,it2+1,l1,l2,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,text1,text2,dp);
    }
};