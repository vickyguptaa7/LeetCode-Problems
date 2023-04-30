class Solution {
public:
    
    vector<int>moveX={1,0,-1,0};
    vector<int>moveY={0,1,0,-1};
    
    bool isPossible(int _x,int _y,vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        return (_x<0||_y<0||_x>=grid.size()||_y>=grid[0].size()||visited[_x][_y]||!grid[_x][_y]);   
    }
    
    int dfsHelper(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        visited[x][y]=true;
        int fishCaught=grid[x][y];
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(isPossible(_x,_y,grid,visited))
                continue;
            fishCaught+=dfsHelper(_x,_y,grid,visited);
        }
        return fishCaught;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxFish=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]||!grid[i][j])
                    continue;
                maxFish=max(maxFish,dfsHelper(i,j,grid,visited));
            }
        }
        return maxFish;
    }
};