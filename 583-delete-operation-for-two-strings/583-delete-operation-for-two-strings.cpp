class Solution {
    int dp[501][501];
public:
    Solution()
    {
        memset(dp,-1,sizeof dp);
    }
    int minDistance(string word1, string word2,int it1=0,int it2=0) {
        int n=word1.size(),m=word2.size();
        
        if(n<=it1||m<=it2)
            return m+n-it1-it2;
        
        if(dp[it1][it2]!=-1)return dp[it1][it2];
        
        if(word1[it1]==word2[it2])
        {
            return dp[it1][it2]=minDistance(word1,word2,it1+1,it2+1);
        }
        else
        {
            return dp[it1][it2]=1+min(minDistance(word1,word2,it1+1,it2),
                         minDistance(word1,word2,it1,it2+1));
        }
    }
};