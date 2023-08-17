class Solution {
    vector<int>moveX={1,-1,0,0};
    vector<int>moveY={0,0,-1,1};
public:
    
    int helper(int x,int y,int cntr,vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        if(cntr==0)
        {
            if(grid[x][y]==2)
                return 1;
            return 0;
        }
        int n=grid.size(),m=grid[0].size();
        visited[x][y]=1;
        int ways=0;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=n||_y>=m||_x<0||_y<0||visited[_x][_y]||grid[_x][_y]==-1)
                continue;
            ways+=helper(_x,_y,cntr-1,grid,visited);
        }
        visited[x][y]=0;
        return ways;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        int n=grid.size(),m=grid[0].size();
        pair<int,int>start;
        int cntr=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    start={i,j};
                else if(grid[i][j]==0)
                    cntr++;
            }
        }
        return helper(start.first,start.second,cntr+1,grid,visited);
    }
};