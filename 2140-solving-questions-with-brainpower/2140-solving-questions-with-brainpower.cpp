class Solution {
public:
     
    long long helper(int start,vector<vector<int>>&questions,vector<long long>&dp)
    {
        if(start>=questions.size())
            return 0;
        if(dp[start]!=-1)
            return dp[start];
        return dp[start]=max(helper(start+1,questions,dp),questions[start][0]+helper(start+questions[start][1]+1,questions,dp));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1,-1);
        return helper(0,questions,dp);
    }
};