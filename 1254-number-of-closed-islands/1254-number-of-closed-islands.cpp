class Solution {
public:
    vector<int>moveX={0,0,-1,1},moveY={1,-1,0,0};
    
    bool helper(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        if(x>=n||x<0||y<0||y>=m)
            return false;
        if(grid[x][y]==1||grid[x][y]==2)
            return true;
        grid[x][y]=2;
        int isValid=true;
        for(int i=0;i<4;i++)
        {
            isValid&=helper(x+moveX[i],y+moveY[i],grid);
        }
        return isValid;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                    continue;
                ans+=helper(i,j,grid);
            }
        }
        return ans;
    }
};