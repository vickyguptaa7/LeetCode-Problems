class Solution {
public:
    
    int helper(int it1,int it2,string &word1,string &word2,vector<vector<int>>&dp)
    {
        if(it1==word1.size())
        {
            return (int)word2.size()-it2;
        }
        if(it2==word2.size())
        {
            return (int)word1.size()-it1;
        }
        if(dp[it1][it2]!=-1)
            return dp[it1][it2];
        
        int mdist=0;
        if(word1[it1]==word2[it2])
        {
            mdist=helper(it1+1,it2+1,word1,word2,dp);
        }
        else 
        {
            mdist=1+min({helper(it1+1,it2,word1,word2,dp),
                      helper(it1,it2+1,word1,word2,dp),
                        helper(it1+1,it2+1,word1,word2,dp)});
        }
        return dp[it1][it2]=mdist;
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(0,0,word1,word2,dp);
    }
};