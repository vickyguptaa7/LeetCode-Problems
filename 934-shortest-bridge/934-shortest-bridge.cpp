class Solution {
public:
    vector<int>moveX={0,0,1,-1};
    vector<int>moveY={1,-1,0,0};
    
    void dfs(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        grid[x][y]=2;
        // cout<<x<<" "<<y<<"\n";
        for(int i=0;i<4;i++)
        {
            int _x=moveX[i]+x,_y=moveY[i]+y;
            if(_x<0||_x>=n||_y<0||_y>=m||grid[_x][_y]!=1)continue;
            dfs(_x,_y,grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            bool isTrue=false;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid);
                    isTrue=true;
                    break;
                }
            }
            if(isTrue)
                break;
        }
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1)
                {
                    visited[i][j]=true;
                    que.push({i,j});
                }
            }
            // cout<<"\n";
        }
        int res=-1;
        while(!que.empty())
        {
            int size=que.size();
            res++;
            while(size--)
            {
                pair<int,int>cor=que.front();
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int _x=cor.first+moveX[i],_y=cor.second+moveY[i];
                    if(_x<0||_x>=n||_y<0||_y>=m||visited[_x][_y]==1)continue;
                    if(grid[_x][_y]==2)return res;
                    visited[_x][_y]=true;
                    que.push({_x,_y});
                }
            }
        }
        return res;
    }
};