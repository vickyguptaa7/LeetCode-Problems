class Solution {
public:
    
    vector<int>moveX={0,0,-1,1},moveY={1,-1,0,0};
    int helper(int x,int y,int time,vector<vector<int>>&grid,
               vector<vector<vector<int>>>&dp,vector<vector<bool>>&visited)
    {
        int n=grid.size();
        if(x==n-1&&y==n-1)
        {
            return time+max(0,grid[x][y]-time);
        }
        
        if(dp[x][y][time]!=-1)
            return dp[x][y][time];
        visited[x][y]=true;
        int mtime=1e9;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=moveY[i]+y;
            if(_x>=n||_y>=n||_y<0||_x<0||visited[_x][_y])
                continue;
            mtime=min(mtime,helper(_x,_y,time+max(0,grid[x][y]-time),grid
                                   ,dp,visited));
        }
        visited[x][y]=false;
        return dp[x][y][time]=mtime;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(
        n,vector<int>(n*n+1,-1)));
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        return helper(0,0,0,grid,dp,visited);
    }
};