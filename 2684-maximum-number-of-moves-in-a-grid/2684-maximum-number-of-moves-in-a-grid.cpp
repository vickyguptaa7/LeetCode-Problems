class Solution {
    vector<int>moveX={-1,0,1};
public:
    
    int helper(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {        
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int ans=0;
        for(int i=0;i<moveX.size();i++)
        {
            int _x=x+moveX[i];
            if(_x<0||_x>=grid.size()||y+1==grid[0].size()||grid[x][y]>=grid[_x][y+1])
            {
                continue;
            }
            ans=max(ans,1+helper(_x,y+1,grid,dp));
        }
        return dp[x][y]=ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,helper(i,0,grid,dp));
        }
        return ans;
    }
};