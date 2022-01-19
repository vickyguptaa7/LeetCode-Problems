class Solution {
public:
    bool isSafe(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& isVisited)
    {
        int r=grid.size(),c=grid[0].size();
        if(row>=r||row<0||col>=c||col<0)return 0;
        else if(grid[row][col]==0)return 0;
        else if(isVisited[row][col]==1)return 0;
        else return 1;
    }
    int Helper(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& isVisited)
    {
        if(!isSafe(row,col,grid,isVisited))return 0;
        isVisited[row][col]=true;
        int right=Helper(row,col+1,grid,isVisited);
        int down=Helper(row+1,col,grid,isVisited);
        int left=Helper(row,col-1,grid,isVisited);
        int up=Helper(row-1,col,grid,isVisited);
        return right+down+left+up+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>>isVisited(row,vector<bool>(col,0));
        int Max_Area=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0||isVisited[i][j]==1)continue;
                Max_Area=max(Max_Area,Helper(i,j,grid,isVisited));
            }
        }
        return Max_Area;
    }
};