class Solution {
public:
    vector<int>moveX={0,0,1,-1},moveY={1,-1,0,0};
    int helper(int x,int y,int nonObstacle,vector<vector<int>>&grid)
    {
        int rows=grid.size(),cols=grid[0].size();
        if(grid[x][y]==2)
            return nonObstacle==1;
        int curr=grid[x][y];
        grid[x][y]=3;
        int ways=0;
        for(int i=0;i<4;i++)
        {
            int _x=moveX[i]+x,_y=moveY[i]+y;
            if(_x>=rows||_y>=cols||_x<0||_y<0||
               grid[_x][_y]==3||grid[_x][_y]==-1)
                continue;
            ways+=helper(_x,_y,nonObstacle-1,grid);
                
        }
        grid[x][y]=curr;
        return ways;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int start_x=0,start_y=0,nonObstacle=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                {
                    start_x=i;
                    start_y=j;
                }
                if(grid[i][j]!=-1)
                    nonObstacle++;
            }
        }
        return helper(start_x,start_y,nonObstacle,grid);
    }
};