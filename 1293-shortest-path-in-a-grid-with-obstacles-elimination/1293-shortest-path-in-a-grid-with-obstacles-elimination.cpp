class Solution {
public:
    vector<int>moveX={0,0,1,-1};
    vector<int>moveY={1,-1,0,0};
    
    int helper(int x,int y,int dir,int k,
               vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp)
    {
        int n=grid.size(),m=grid[0].size();
        if(dp[x][y][k][dir]!=-1)
            return dp[x][y][k][dir];
        
        if(x==n-1&&y==m-1)
        {
            return 0;
        }
        
        int minStep=1e9;
        int prev=grid[x][y];
        grid[x][y]=3;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x<0||_y<0||_x>=n||_y>=m||(k==0&&grid[_x][_y]==1)||grid[_x][_y]==3)
                continue;
            minStep=min(minStep,1+helper(_x,_y,i,k-grid[_x][_y],grid,dp));
        }
        grid[x][y]=prev;
        return dp[x][y][k][dir]=minStep;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        if(k>=m+n-2)
        {
            return m+n-2;
        }
        vector<vector<vector<vector<int>>>>dp(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(k+1,vector<int>(4,-1))));
        int ans=helper(0,0,0,k,grid,dp);
        return ans==1e9?-1:ans;
    }
};