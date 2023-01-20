class Solution {
public:
    vector<int>moveX={1,-1,0,0},moveY={0,0,1,-1};
    int dfs(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        grid[x][y]=2;
        int ans=1;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=moveY[i]+y;
            if(_x>=n||_y>=m||_x<0||_y<0||grid[_x][_y]!=1)
                continue;
            ans+=dfs(_x,_y,grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea,dfs(i,j,grid));
                }
            }
        }
        for(auto &x:grid)
        {
            for(auto y:x)
            {
                if(y==2)y=1;
            }
        }
        return maxArea;
    }
};