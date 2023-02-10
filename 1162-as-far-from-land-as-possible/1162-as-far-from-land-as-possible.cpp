class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>que;
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    que.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        if(que.empty()||que.size()==n*n)
            return -1;
        int dist=0;
        vector<int>moveX={0,0,-1,1},moveY={1,-1,0,0};
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int _x=x+moveX[i],_y=moveY[i]+y;
                    if(_x>=n||_y>=n||_y<0||_x<0||visited[_x][_y])
                        continue;
                    visited[_x][_y]=true;
                    que.push({_x,_y});
                }
            }
            dist++;
        }
        return dist-1;
    }
};