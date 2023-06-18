class Solution {
public:
    
    vector<int>moveX={0,0,1,-1},moveY={1,-1,0,0};
    
    int helper(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        int n=grid.size(),m=grid[0].size();
        int ways=0,mod=1e9+7;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x<0||_y<0||_y>=m||_x>=n||grid[x][y]>=grid[_x][_y])continue;
            ways+=helper(_x,_y,grid,dp)+1;
            ways%=mod;
        }
        return dp[x][y]=ways;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int counts=0,mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                counts+=1+helper(i,j,grid,dp);
                counts%=mod;
            }
        }
        return counts;
    }
};