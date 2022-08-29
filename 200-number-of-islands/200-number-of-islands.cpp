class Solution {
public:
    vector<int>moveX={0,0,1,-1};
    vector<int>moveY={1,-1,0,0};
    void dfs(int x,int y,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        int rows=grid.size(),cols=grid[0].size();
        visited[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x<0||_y<0||_x>=rows||_y>=cols||grid[_x][_y]=='0'||visited[_x][_y])continue;
            dfs(_x,_y,grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int cntr=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    dfs(i,j,grid,visited);
                    cntr++;
                }
            }
        }
        return cntr;
    }
};