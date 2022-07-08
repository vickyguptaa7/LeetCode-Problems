class Solution {
public:
    int helper(int s,int target,int color,int n,vector<vector<int>>&cost,
               vector<int>&house,vector<vector<vector<int>>>&dp)
    {
        if(target<1)return 1e9;
        if(s==house.size())
        {
            if(target!=1)return 1e9;
            return 0;
        }
        
        if(dp[s][target][color]!=-1)return dp[s][target][color];
        
        if(house[s]!=0)
        {
            if(s!=0&&house[s]!=house[s-1])
                return helper(s+1,target-1,house[s],n,cost,house,dp);
            
            return helper(s+1,target,house[s],n,cost,house,dp);
        }
        
        int minCost=1e9;
        for(int i=0;i<n;i++)
        {
            if(s!=0&&i+1!=house[s-1])
            {
                if(target<=1)continue;
                house[s]=i+1;
                minCost=min(minCost,cost[s][i]+helper(s+1,target-1,i+1,n,cost,house,dp));
                house[s]=0;
            }
            else
            {
                house[s]=i+1;
                minCost=min(minCost,cost[s][i]+helper(s+1,target,i+1,n,cost,house,dp));
                house[s]=0; 
            }
        }
        return dp[s][target][color]=minCost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans=helper(0,target,houses[0],n,cost,houses,dp);
        return ans==1e9?-1:ans;
    }
};