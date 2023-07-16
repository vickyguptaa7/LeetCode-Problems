class Solution {
public:
    
    int helper(int start,int end,vector<int>&values,vector<vector<int>>&dp)
    {
        if(end-start<2)
            return 0;
        if(end-start==2)
        {
            return values[start]*values[end]*values[start+1];
        }
        if(dp[start][end]!=-1)
            return dp[start][end];
        int mnWay=1e9;
        for(int i=start+1;i<end;i++)
        {
            mnWay=min(mnWay,values[start]*values[end]*values[i]+
                      helper(i,end,values,dp)+helper(start,i,values,dp));
        }
        return dp[start][end]=mnWay;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(),vector<int>(values.size(),-1));
        return helper(0,(int)values.size()-1,values,dp);
    }
};