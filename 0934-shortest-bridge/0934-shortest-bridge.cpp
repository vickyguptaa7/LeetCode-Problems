class Solution {
    
    vector<int>moveX={0,0,-1,1};
    vector<int>moveY={1,-1,0,0};
    
    void dfsMarker(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        grid[x][y]=2;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=n||_y>=m||_x<0||_y<0||grid[_x][_y]!=1)continue;
            dfsMarker(_x,_y,grid);    
        }
    }
    
    int helper(vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>que;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=true;
                    que.push({i,j});
                    
                }
            }
        }
        int bsize=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                auto x=que.front().first;
                auto y=que.front().second;
                que.pop();
                if(grid[x][y]==1)
                    return bsize-1;
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=y+moveY[i];
                    if(_x>=n||_y>=m||_x<0||_y<0||visited[_x][_y])continue;
                    visited[_x][_y]=true;
                    que.push({_x,_y});
                }
            }
            bsize++;
        }
        return -1;
    }
    
public:
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            bool isFound=false;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    isFound=true;
                    dfsMarker(i,j,grid);
                    break;
                }
            }
            if(isFound)break;
        }
        return helper(grid);
    }
};