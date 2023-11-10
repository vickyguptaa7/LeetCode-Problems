class Solution {
public:
    
    int helper(int src,int par,int div,vector<int>list[],vector<int>&coins,int k,vector<vector<int>>&dp)
    {
        if(div==19)
            return 0;
        
        if(dp[src][div]!=-1)
            return dp[src][div];
        
        int first=0,second=0;
        
        for(auto child:list[src])
        {
            if(par==child)continue;
            first+=helper(child,src,div,list,coins,k,dp);
            second+=helper(child,src,div+1,list,coins,k,dp);
        }
        int coin=+(coins[src]/(1<<(div)));
        return dp[src][div]=max(first+coin-k,second+coin/2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=edges.size()+1;
        vector<int>list[n];
        for(auto edge:edges)
        {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>>dp(n,vector<int>(20,-1));
        return helper(0,-1,0,list,coins,k,dp);
    }
};