class Solution {
public:

    bool dfs(int src,int par,int tar,vector<int>list[],vector<vector<int>>&dp)
    {
        if(src==tar)
            return dp[src][tar]=true;

        if(dp[src][tar]!=-1)
            return dp[src][tar];

        for(auto child:list[src])
        {
            if(child!=par&&dfs(child,src,tar,list,dp))
            {
                return dp[src][tar]=true;
            }
        }
        return dp[src][tar]=false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        vector<int>list[n];
        for(int i=0;i<pre.size();i++)
        {
            list[pre[i][0]].push_back(pre[i][1]);
        }
        vector<bool>ans;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<que.size();i++)
        {
            int u=que[i][0],v=que[i][1];
            ans.push_back(dfs(u,-1,v,list,dp));
        }
        return ans;
    }
};