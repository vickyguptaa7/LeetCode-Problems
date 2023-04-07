class Solution {
public:
    vector<int>moveX={1,-1,0,0};
    vector<int>moveY={0,0,-1,1};
    
    void dfsHelper(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&visited,bool &isBoundary,int &nodeCnt)
    {
        int n=grid.size(),m=grid[0].size();
        nodeCnt++;
        visited[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int _x=x+moveX[i],_y=y+moveY[i];
            if(_x>=n||_y>=m||_x<0||_y<0)
            {
                isBoundary=true;
                continue;
            }
            if(visited[_x][_y]||!grid[_x][_y])
                continue;
            dfsHelper(_x,_y,grid,visited,isBoundary,nodeCnt);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int enclaves=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]||!grid[i][j])continue;
                bool isBoundary=false;
                int nodeCnt=0;
                dfsHelper(i,j,grid,visited,isBoundary,nodeCnt);
                if(!isBoundary)
                    enclaves+=nodeCnt;
            }
        }
        return enclaves;
    }
};